#include "processing.h"

void negative(int pgm_image[][MAX], int width, int height, int gray_scale)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            pgm_image[i][j] = gray_scale - pgm_image[i][j];
        }
    }
}

void thresholding(int pgm_image[][MAX], int width, int height, int gray_scale, int threshold_level)
{
    int local_threshold_level = (threshold_level * gray_scale) / 100;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (pgm_image[i][j] <= local_threshold_level)
            {
                pgm_image[i][j] = 0;
            }
            else
            {
                pgm_image[i][j] = gray_scale;
            }
        }
    }
}

void thresholding_black(int pgm_image[][MAX], int width, int height, int gray_scale, int threshold_level)
{
    int local_threshold_level = (threshold_level * gray_scale) / 100;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (pgm_image[i][j] <= local_threshold_level)
            {
                pgm_image[i][j] = 0;
            }
            else
            {
                pgm_image[i][j] = pgm_image[i][j];
            }
        }
    }
}

void thresholding_white(int pgm_image[][MAX], int width, int height, int gray_scale, int threshold_level)
{
    int local_threshold_level = (threshold_level * gray_scale) / 100;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (pgm_image[i][j] <= local_threshold_level)
            {
                pgm_image[i][j] = pgm_image[i][j];
            }
            else
            {
                pgm_image[i][j] = gray_scale;
            }
        }
    }
}

void gamma_correction(int pgm_image[][MAX], int width, int height, int gray_scale, float gamma_parameter)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            pgm_image[i][j] = (pow(pgm_image[i][j], (1 / (gamma_parameter)))) / (pow(gray_scale, (1 - gamma_parameter) / (gamma_parameter)));
        }
    }
}

void change_levels(int pgm_image[][MAX], int width, int height, int gray_scale, int white, int black)
{

    int local_white = (white * gray_scale) / 100;
    int local_black = (black * gray_scale) / 100;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (pgm_image[i][j] <= local_black)
            {
                pgm_image[i][j] = 0;
            }
            else if ((local_black < pgm_image[i][j]) && (pgm_image[i][j] < local_white))
            {
                pgm_image[i][j] = (pgm_image[i][j] - local_black) * (gray_scale / (local_white - local_black));
            }
            else
            {
                pgm_image[i][j] = gray_scale;
            }
        }
    }
}

void contouring(int pgm_image[][MAX], int width, int height, int gray_scale)
{
    for (int i = 0; i < height - 1; i++)
    {
        for (int j = 0; j < width - 1; j++)
        {
            pgm_image[i][j] = abs(pgm_image[i + 1][j] - pgm_image[i][j]) + abs(pgm_image[i][j + 1] - pgm_image[i][j]);
        }
    }
}

void horizontal_blur(int pgm_image[][MAX], int width, int height, int gray_scale)
{
    for (int i = 2; i < height - 2; i++)
    {
        for (int j = 2; j < width; j++)
        {
            pgm_image[i][j] = ((pgm_image[i - 2][j] + pgm_image[i - 1][j] + pgm_image[i][j] + pgm_image[i + 1][j] + pgm_image[i + 2][j])) / 5;
        }
    }
}

void vertical_blur(int pgm_image[][MAX], int width, int height, int gray_scale)
{
    for (int i = 2; i < height; i++)
    {
        for (int j = 2; j < width - 2; j++)
        {
            pgm_image[i][j] = ((pgm_image[i][j - 2] + pgm_image[i][j - 1] + pgm_image[i][j] + pgm_image[i][j + 1] + pgm_image[i][j + 2])) / 5;
        }
    }
}