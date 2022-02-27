#ifndef UTILITY_H_
#define UTILITY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defines.h"

/**
 * @brief Loads a PGM image from a file into an array
 *
 * @param input_file image file in PGM format
 * @param pgm_image array to which the image will be written
 * @param width image width
 * @param height image height
 * @param gray_scale number of shades of gray
 * @return int number of loaded pixels
 */
int read_image(FILE *input_file, int pgm_image[][*], int *width, int *height, int *gray_scale);

/**
 * @brief Saves a PGM image from an array into a file
 *
 * @param output_file image file in PGM format
 * @param pgm_image array from which the image will be written
 * @param width image width
 * @param height image height
 * @param gray_scale number of shades of gray
 * @return int number of saved pixels
 */
int save_image(FILE *output_file, int pgm_image[][*], int *width, int *height, int *gray_scale);

/**
 * @brief Display image with built in application
 *
 * @param file_name name of the file we want to display
 */
void display(char *file_name);

/**
 * @brief Dispalys menu
 *
 */
void display_menu();

#endif // UTILITY_H_