#ifndef PROCESSING_H_
#define PROCESSING_H_

#include <math.h>
#include <limits.h>
#include <stdlib.h>
#include "defines.h"

/**
 * @brief Negative operation
 *
 * @param pgm_image processed image
 * @param width image wdith
 * @param height image height
 * @param gray_scale number of shades of gray
 */
void negative(int pgm_image[][*], int width, int height, int gray_scale);

/**
 * @brief Thresholding operation
 *
 * @param pgm_image processed image
 * @param width image wdith
 * @param height image height
 * @param gray_scale number of shades of gray
 * @param threshold_level
 */
void thresholding(int pgm_image[][*], int width, int height, int gray_scale, int threshold_level);

/**
 * @brief Half-thresholding operation, thresholding black colour
 *
 * @param pgm_image processed image
 * @param width image wdith
 * @param height image height
 * @param gray_scale number of shades of gray
 * @param threshold_level
 */
void thresholding_black(int pgm_image[][*], int width, int height, int gray_scale, int threshold_level);

/**
 * @brief Half-thresholding operation, thresholding white colour
 *
 * @param pgm_image processed image
 * @param width image wdith
 * @param height image height
 * @param gray_scale number of shades of gray
 * @param threshold_level
 */
void thresholding_white(int pgm_image[][*], int width, int height, int gray_scale, int threshold_level);

/**
 * @brief Gamma correction operation
 *
 * @param pgm_image processed image
 * @param width image wdith
 * @param height image height
 * @param gray_scale number of shades of gray
 * @param gamma_parameter
 */
void gamma_correction(int pgm_image[][*], int width, int height, int gray_scale, float gamma_parameter);

/**
 * @brief Change levels of white and black colour
 *
 * @param pgm_image processed image
 * @param width image wdith
 * @param height image height
 * @param gray_scale number of shades of gra
 * @param white new white level
 * @param black new black level
 */
void change_levels(int pgm_image[][*], int width, int height, int gray_scale, int white, int black);

/**
 * @brief Contouring operation
 *
 * @param pgm_image processed image
 * @param width image wdith
 * @param height image height
 * @param gray_scale number of shades of gray
 */
void contouring(int pgm_image[][*], int width, int height, int gray_scale);

/**
 * @brief Horizontal blur operation with 2 radius.
 *
 * @param pgm_image processed image
 * @param width image wdith
 * @param height image height
 * @param gray_scale number of shades of gray
 */
void horizontal_blur(int pgm_image[][*], int width, int height, int gray_scale);

/**
 * @brief Vertical blur operation with 2 radius.
 *
 * @param pgm_image processed image
 * @param width image wdith
 * @param height image height
 * @param gray_scale number of shades of gray
 */
void vertical_blur(int pgm_image[][*], int width, int height, int gray_scale);

#endif // PROCESSING_H_