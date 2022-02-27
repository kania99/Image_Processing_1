#include "utility.h"

int read_image(FILE *input_file, int pgm_image[][MAX], int *width, int *height, int *gray_scale)
{
    char buffer[LINE_LENGTH]; /* auxiliary buffer for reading the header and comments */
    int hash_sign;            /* auxiliary variable for reading comments */
    int end_of_data = 0;      /* whether the end of data in the file is encountered */
    int i, j;

    /* Verifies that a valid file is provided */
    if (input_file == NULL)
    {
        fprintf(stderr, "Error: A file handle was not specified!\n");
        return 0;
    }

    /* Magic number check - should be P2 */
    if (fgets(buffer, LINE_LENGTH, input_file) == NULL) /* Reading the first line of the file into the buffer */
    {
        end_of_data = 1; /* Failed, end of data! */
    }

    if ((buffer[0] != 'P') || (buffer[1] != '2') || end_of_data)
    { /* Is there a magic "P2"?*/
        fprintf(stderr, "Error: This is not a PGM file!\n");
        return 0;
    }

    /* Skipping comments */
    do
    {
        if ((hash_sign = fgetc(input_file)) == '#') /* Does the line begin with '#'? */
        {
            if (fgets(buffer, LINE_LENGTH, input_file) == NULL)
            {
                end_of_data = 1;
            }
        }
        else
        {
            ungetc(hash_sign, input_file); /* If the read character is not '#' return it */
        }
    } while (hash_sign == '#' && !end_of_data); /* Repeat as long as there are comment lines and no data end_of_data occurred*/

    /* Get image dimensions and number of shades of gray */
    if (fscanf(input_file, "%d %d %d", width, height, gray_scale) != 3)
    {
        fprintf(stderr, "Error: No image dimensions or number of grayscale!\n");
        return 0;
    }
    /* Image download and save to array pgm_image */
    for (i = 0; i < *height; i++)
    {
        for (j = 0; j < *width; j++)
        {
            if (fscanf(input_file, "%d", &(pgm_image[i][j])) != 1)
            {
                fprintf(stderr, "Error: Wrong image dimensions!\n");
                return 0;
            }
        }
    }
    return *width * *height; /* Successful reading */
} /* Return the number of loaded pixels */

int save_image(FILE *output_file, int pgm_image[][MAX], int *width, int *height, int *gray_scale)
{
    int line_breaker = 0;
    int i, j;

    /* Verifies that a valid file is provided */
    if (output_file == NULL)
    {
        fprintf(stderr, "Error: A file handle was not specified!\n");
        return 0;
    }

    /*Print magic number and image parameters */
    fprintf(output_file, "P2\n");
    fprintf(output_file, "%d %d\n%d\n", *width, *height, *gray_scale);

    for (i = 0; i < *height; i++)
    {
        for (j = 0; j < *width; j++)
        {
            fprintf(output_file, "%d ", (pgm_image[i][j]));
            line_breaker++;
            /*Go to new line after PGM_LINE characters*/
            if (line_breaker % PGM_LINIE == 0)
            {
                fprintf(output_file, "\n");
                line_breaker = 0;
            }
        }
    }
    return *width * *height; /* Successful saving */
} /* Return the number of saved pixels */

void display(char *file_name)
{
    char command[LINE_LENGTH]; /* auxiliary buffer */

    strcpy(command, "display "); /* command structure */
    strcat(command, file_name);  /* display "file_name" */
    strcat(command, " &");
    // printf("%s\n", command); /* command test print */
    system(command); /* execute the command */
}

void display_menu()
{
    system("clear");
    printf("\nImage processing:\n\n");
    printf(" 1. Load image\n");
    printf(" 2. Save and display image\n");
    printf(" 3. Negative\n");
    printf(" 4. Thresholding\n");
    printf(" 5. Thresholding black\n");
    printf(" 6. Thresholding white\n");
    printf(" 7. Gamma correction\n");
    printf(" 8. Change levels\n");
    printf(" 9. Contouring\n");
    printf("10. Horizontal blur\n");
    printf("11. Vertical blur\n");
    printf("12. End program\n\n");
}