#include <stdint.h>
#include <errno.h>

#define STB_IMAGE_IMPLEMENTATION
#include "../../../submodules/nothings/stb/stb_image.h"

#define QM_COLOR_TRANSPARENT 1
#define QM_COLOR_BLACK 2
#define QM_COLOR_WHITE 4

typedef uint8_t qm_color_t;

int main(int argc, const char ** argv) {
  if (argc != 7) {
    fprintf(stderr, "expected 6 arguments, actual %d\n", argc - 1);
    return 1;
  } else {
    const char * path_to_library_header = argv[1];
    const char * path_to_output_header = argv[2];
    const char * path_to_output_source = argv[3];
    const char * variable_name = argv[4];
    const char * guard_name = argv[5];
    const char * header_name = argv[6];

    int uncropped_columns;
    int uncropped_rows;

    uint8_t * uncropped_rgba = stbi_load_from_file(stdin, &uncropped_columns, &uncropped_rows, NULL, 4);

    if (uncropped_rgba) {
      int left_transparent_columns;

      for (left_transparent_columns = 0; left_transparent_columns < uncropped_columns; left_transparent_columns++) {
        int row;

        for (row = 0; row < uncropped_rows; row++) {
          if (uncropped_rgba[row * uncropped_columns * 4 + left_transparent_columns * 4 + 3]) {
            break;
          }
        }

        if (row < uncropped_rows) {
          break;
        }
      }

      if (left_transparent_columns == uncropped_columns) {
        fprintf(stderr, "all pixels in the input file are transparent\n");
        return 1;
      } else if (left_transparent_columns > 127) {
        fprintf(stderr, "the left %d columns are transparent (the limit being 127)\n", left_transparent_columns);
        return 1;
      } else {
        int right_transparent_columns;

        for (right_transparent_columns = 0; ; right_transparent_columns++) {
          int row;

          for (row = 0; row < uncropped_rows; row++) {
            if (uncropped_rgba[row * uncropped_columns * 4 + (uncropped_columns - right_transparent_columns - 1) * 4 + 3]) {
              break;
            }
          }

          if (row < uncropped_rows) {
            break;
          }
        }

        int cropped_columns = uncropped_columns - left_transparent_columns - right_transparent_columns;

        int rounded_up_cropped_columns = cropped_columns % 8 == 0 ? cropped_columns : cropped_columns - (cropped_columns % 8) + 8;

        if (rounded_up_cropped_columns > 255) {
          fprintf(stderr, "the cropped area is %d columns wide when rounded up to the nearest 8 columns (the limit being 255)\n", cropped_columns);
          return 1;
        } else {
          int top_transparent_rows;

          for (top_transparent_rows = 0; ; top_transparent_rows++) {
            int column;

            for (column = left_transparent_columns; column < uncropped_columns - right_transparent_columns; column++) {
              if (uncropped_rgba[top_transparent_rows * uncropped_columns * 4 + column * 4 + 3]) {
                break;
              }
            }

            if (column < uncropped_columns - right_transparent_columns) {
              break;
            }
          }

          if (top_transparent_rows > 127) {
            fprintf(stderr, "the top %d rows are transparent (the limit being 127)\n", top_transparent_rows);
            return 1;
          } else {
            int bottom_transparent_rows;

            for (bottom_transparent_rows = 0; ; bottom_transparent_rows++) {
              int column;

              for (column = left_transparent_columns; column < uncropped_columns - right_transparent_columns; column++) {
                if (uncropped_rgba[(uncropped_rows - bottom_transparent_rows - 1) * uncropped_columns * 4 + column * 4 + 3]) {
                  break;
                }
              }

              if (column < uncropped_columns - right_transparent_columns) {
                break;
              }
            }

            int cropped_rows = uncropped_rows - top_transparent_rows - bottom_transparent_rows;

            if (cropped_rows > 255) {
              fprintf(stderr, "the cropped area is %d rows tall (the limit being 255)\n", cropped_rows);
              return 1;
            } else {
              qm_color_t * cropped_colors = (qm_color_t *) malloc(sizeof(qm_color_t) * rounded_up_cropped_columns * cropped_rows);

              if (cropped_colors) {
                qm_color_t encountered_colors = 0;

                int cropped_index = 0;

                for (int cropped_row = 0; cropped_row < cropped_rows; cropped_row++) {
                  int uncropped_row = cropped_row + top_transparent_rows;

                  for (int cropped_column = 0; cropped_column < rounded_up_cropped_columns; cropped_column++) {
                    qm_color_t this_color;

                    if (cropped_column < cropped_columns) {
                      int uncropped_column = cropped_column + left_transparent_columns;

                      int uncropped_index = uncropped_row * uncropped_columns * 4 + uncropped_column * 4;



                      switch (uncropped_rgba[uncropped_index + 3]) {
                        case 0:
                          this_color = QM_COLOR_TRANSPARENT;
                          break;

                        case 255: {
                          uint8_t red = uncropped_rgba[uncropped_index];
                          uint8_t green = uncropped_rgba[uncropped_index + 1];
                          uint8_t blue = uncropped_rgba[uncropped_index + 2];

                          if (red == 0 && green == 0 && blue == 0) {
                            this_color = QM_COLOR_BLACK;
                            break;
                          } else if (red == 255 && green == 255 && blue == 255) {
                            this_color = QM_COLOR_WHITE;
                            break;
                          } else {
                            fprintf(stderr, "the pixel at column %d, row %d is not transparent, black or white\n", uncropped_column, uncropped_row);
                            return 1;
                          }
                        }

                        default:
                          fprintf(stderr, "the pixel at column %d, row %d is semi-transparent\n", uncropped_column, uncropped_row);
                          return 1;
                      }

                      encountered_colors |= this_color;
                    } else {
                      this_color = QM_COLOR_TRANSPARENT;
                    }

                    cropped_colors[cropped_index] = this_color;
                    cropped_index++;
                  }
                }

                FILE * header_file = fopen(path_to_output_header, "w");

                if (header_file) {
                  if (fprintf(header_file, "#ifndef %s\n\n#define %s\n\n#include \"%s\"\n\nextern const qm_sprite_t %s QM_STATIC_DATA;\n\n#endif\n", guard_name, guard_name, path_to_library_header, variable_name) < 0) {
                      fprintf(stderr, "failed to write to %s; error no %d\n", path_to_output_header, ferror(header_file));
                      return 1;
                  } else {
                    FILE * source_file = fopen(path_to_output_source, "w");

                    if (source_file) {
                      if (fprintf(source_file, "#include \"%s\"\n#include \"%s\"\n\nconst qm_sprite_t %s QM_STATIC_DATA = {\n  %d,\n  %d,\n  %d,\n  %d,\n  ", path_to_library_header, header_name, variable_name, cropped_columns, cropped_rows, left_transparent_columns, top_transparent_rows) < 0) {
                          fprintf(stderr, "failed to write to %s; error no %d\n", path_to_output_source, ferror(source_file));
                          return 1;
                      } else {
                        switch (encountered_colors) {
                          case QM_COLOR_BLACK:
                            if (fprintf(source_file, "QM_SPRITE_ENCODING_BLACK,\n};\n") < 0) {
                                fprintf(stderr, "failed to write to %s; error no %d\n", path_to_output_source, ferror(source_file));
                                return 1;
                            } else {
                              return 0;
                            }

                          case QM_COLOR_WHITE:
                            if (fprintf(source_file, "QM_SPRITE_ENCODING_WHITE,\n};\n") < 0) {
                                fprintf(stderr, "failed to write to %s; error no %d\n", path_to_output_source, ferror(source_file));
                                return 1;
                            } else {
                              return 0;
                            }

                          case QM_COLOR_BLACK | QM_COLOR_WHITE:
                            if (fprintf(source_file, "QM_SPRITE_ENCODING_BLACK_AND_WHITE,\n  {") < 0) {
                                fprintf(stderr, "failed to write to %s; error no %d\n", path_to_output_source, ferror(source_file));
                                return 1;
                            } else {
                              for (int cropped_row = 0; cropped_row < cropped_rows; cropped_row++) {
                                if (fprintf(source_file, "\n   ") < 0) {
                                  fprintf(stderr, "failed to write to %s; error no %d\n", path_to_output_source, ferror(source_file));
                                  return 1;
                                }

                                for (int cropped_column = 0; cropped_column < rounded_up_cropped_columns; cropped_column++) {
                                  if (cropped_column % 8 == 0 && fprintf(source_file, " 0b") < 0) {
                                    fprintf(stderr, "failed to write to %s; error no %d\n", path_to_output_source, ferror(source_file));
                                    return 1;
                                  } else {
                                    int character;

                                    switch (cropped_colors[cropped_column + cropped_row * rounded_up_cropped_columns]) {
                                      case QM_COLOR_BLACK:
                                      case QM_COLOR_TRANSPARENT:
                                        character = '0';
                                        break;

                                      case QM_COLOR_WHITE:
                                        character = '1';
                                        break;

                                      default:
                                        fprintf(stderr, "unexpected color in cropped buffer\n");
                                        return 1;
                                    }

                                    if (fputc(character, source_file) == EOF) {
                                      fprintf(stderr, "failed to write to %s; error no %d\n", path_to_output_source, ferror(source_file));
                                      return 1;
                                    } else if (cropped_column % 8 == 7 && fputc(',', source_file) == EOF) {
                                      fprintf(stderr, "failed to write to %s; error no %d\n", path_to_output_source, ferror(source_file));
                                      return 1;
                                    }
                                  }
                                }
                              }

                              if (fprintf(source_file, "\n  },\n};\n") < 0) {
                                fprintf(stderr, "failed to write to %s; error no %d\n", path_to_output_source, ferror(source_file));
                                return 1;
                              } else {
                                return 0;
                              }
                            }

                          case QM_COLOR_BLACK | QM_COLOR_TRANSPARENT:
                            if (fprintf(source_file, "QM_SPRITE_ENCODING_BLACK_AND_TRANSPARENT,\n  {") < 0) {
                                fprintf(stderr, "failed to write to %s; error no %d\n", path_to_output_source, ferror(source_file));
                                return 1;
                            } else {
                              for (int cropped_row = 0; cropped_row < cropped_rows; cropped_row++) {
                                if (fprintf(source_file, "\n   ") < 0) {
                                  fprintf(stderr, "failed to write to %s; error no %d\n", path_to_output_source, ferror(source_file));
                                  return 1;
                                }

                                for (int cropped_column = 0; cropped_column < rounded_up_cropped_columns; cropped_column++) {
                                  if (cropped_column % 8 == 0 && fprintf(source_file, " 0b") < 0) {
                                    fprintf(stderr, "failed to write to %s; error no %d\n", path_to_output_source, ferror(source_file));
                                    return 1;
                                  } else {
                                    int character;

                                    switch (cropped_colors[cropped_column + cropped_row * rounded_up_cropped_columns]) {
                                      case QM_COLOR_BLACK:
                                        character = '0';
                                        break;

                                      case QM_COLOR_TRANSPARENT:
                                        character = '1';
                                        break;

                                      default:
                                        fprintf(stderr, "unexpected color in cropped buffer\n");
                                        return 1;
                                    }

                                    if (fputc(character, source_file) == EOF) {
                                      fprintf(stderr, "failed to write to %s; error no %d\n", path_to_output_source, ferror(source_file));
                                      return 1;
                                    } else if (cropped_column % 8 == 7 && fputc(',', source_file) == EOF) {
                                      fprintf(stderr, "failed to write to %s; error no %d\n", path_to_output_source, ferror(source_file));
                                      return 1;
                                    }
                                  }
                                }
                              }

                              if (fprintf(source_file, "\n  },\n};\n") < 0) {
                                fprintf(stderr, "failed to write to %s; error no %d\n", path_to_output_source, ferror(source_file));
                                return 1;
                              } else {
                                return 0;
                              }
                            }

                          case QM_COLOR_WHITE | QM_COLOR_TRANSPARENT:
                            if (fprintf(source_file, "QM_SPRITE_ENCODING_WHITE_AND_TRANSPARENT,\n  {") < 0) {
                                fprintf(stderr, "failed to write to %s; error no %d\n", path_to_output_source, ferror(source_file));
                                return 1;
                            } else {
                              for (int cropped_row = 0; cropped_row < cropped_rows; cropped_row++) {
                                if (fprintf(source_file, "\n   ") < 0) {
                                  fprintf(stderr, "failed to write to %s; error no %d\n", path_to_output_source, ferror(source_file));
                                  return 1;
                                }

                                for (int cropped_column = 0; cropped_column < rounded_up_cropped_columns; cropped_column++) {
                                  if (cropped_column % 8 == 0 && fprintf(source_file, " 0b") < 0) {
                                    fprintf(stderr, "failed to write to %s; error no %d\n", path_to_output_source, ferror(source_file));
                                    return 1;
                                  } else {
                                    int character;

                                    switch (cropped_colors[cropped_column + cropped_row * rounded_up_cropped_columns]) {
                                      case QM_COLOR_TRANSPARENT:
                                        character = '0';
                                        break;

                                      case QM_COLOR_WHITE:
                                        character = '1';
                                        break;

                                      default:
                                        fprintf(stderr, "unexpected color in cropped buffer\n");
                                        return 1;
                                    }

                                    if (fputc(character, source_file) == EOF) {
                                      fprintf(stderr, "failed to write to %s; error no %d\n", path_to_output_source, ferror(source_file));
                                      return 1;
                                    } else if (cropped_column % 8 == 7 && fputc(',', source_file) == EOF) {
                                      fprintf(stderr, "failed to write to %s; error no %d\n", path_to_output_source, ferror(source_file));
                                      return 1;
                                    }
                                  }
                                }
                              }

                              if (fprintf(source_file, "\n  },\n};\n") < 0) {
                                fprintf(stderr, "failed to write to %s; error no %d\n", path_to_output_source, ferror(source_file));
                                return 1;
                              } else {
                                return 0;
                              }
                            }

                          case QM_COLOR_TRANSPARENT | QM_COLOR_BLACK | QM_COLOR_WHITE:
                            if (fprintf(source_file, "QM_SPRITE_ENCODING_BLACK_WHITE_AND_TRANSPARENT,\n  {") < 0) {
                                fprintf(stderr, "failed to write to %s; error no %d\n", path_to_output_source, ferror(source_file));
                                return 1;
                            } else {
                              for (int cropped_row = 0; cropped_row < cropped_rows; cropped_row++) {
                                if (fprintf(source_file, "\n   ") < 0) {
                                  fprintf(stderr, "failed to write to %s; error no %d\n", path_to_output_source, ferror(source_file));
                                  return 1;
                                }

                                for (int cropped_column = 0; cropped_column < rounded_up_cropped_columns; cropped_column += 8) {
                                  if (fprintf(source_file, " 0b") < 0) {
                                    fprintf(stderr, "failed to write to %s; error no %d\n", path_to_output_source, ferror(source_file));
                                    return 1;
                                  } else {
                                    for (int bit_column = cropped_column; bit_column < cropped_column + 8; bit_column++) {
                                      int character;

                                      switch (cropped_colors[bit_column + cropped_row * rounded_up_cropped_columns]) {
                                        case QM_COLOR_TRANSPARENT:
                                          character = '1';
                                          break;

                                        case QM_COLOR_BLACK:
                                        case QM_COLOR_WHITE:
                                          character = '0';
                                          break;

                                        default:
                                          fprintf(stderr, "unexpected color in cropped buffer\n");
                                          return 1;
                                      }

                                      if (fputc(character, source_file) == EOF) {
                                        fprintf(stderr, "failed to write to %s; error no %d\n", path_to_output_source, ferror(source_file));
                                        return 1;
                                      }
                                    }

                                    if (fprintf(source_file, ", 0b") < 0) {
                                      fprintf(stderr, "failed to write to %s; error no %d\n", path_to_output_source, ferror(source_file));
                                      return 1;
                                    } else {
                                      for (int bit_column = cropped_column; bit_column < cropped_column + 8; bit_column++) {
                                        int character;

                                        switch (cropped_colors[bit_column + cropped_row * rounded_up_cropped_columns]) {
                                          case QM_COLOR_TRANSPARENT:
                                          case QM_COLOR_BLACK:
                                            character = '0';
                                            break;

                                          case QM_COLOR_WHITE:
                                            character = '1';
                                            break;

                                          default:
                                            fprintf(stderr, "unexpected color in cropped buffer\n");
                                            return 1;
                                        }

                                        if (fputc(character, source_file) == EOF) {
                                          fprintf(stderr, "failed to write to %s; error no %d\n", path_to_output_source, ferror(source_file));
                                          return 1;
                                        }
                                      }

                                      if (fputc(',', source_file) == EOF) {
                                        fprintf(stderr, "failed to write to %s; error no %d\n", path_to_output_source, ferror(source_file));
                                        return 1;
                                      }
                                    }
                                  }
                                }
                              }

                              if (fprintf(source_file, "\n  },\n};\n") < 0) {
                                fprintf(stderr, "failed to write to %s; error no %d\n", path_to_output_source, ferror(source_file));
                                return 1;
                              } else {
                                return 0;
                              }
                            }
                        }
                      }
                    } else {
                      fprintf(stderr, "failed to open %s for writing; error no %d\n", path_to_output_header, errno);
                      return 1;
                    }
                  }
                } else {
                  fprintf(stderr, "failed to open %s for writing; error no %d\n", path_to_output_header, errno);
                  return 1;
                }
              } else {
                fprintf(stderr, "failed to allocate memory for a cropped image\n");
                return 1;
              }
            }
          }
        }
      }
    } else {
      fprintf(stderr, "failed to load image; %s\n", stbi_failure_reason());
      return 1;
    }
  }
}
