#include <stdbool.h>
#include "processing.h"
#include "utility.h"
#include "defines.h"

int main()
{
    int image[MAX][MAX];
    int width, height, gray, threshold_level, white, black, menu;
    float gamma_parameter;
    bool is_image_loaded = false;

    int loaded_number_of_pixels = 0;
    int saved_number_of_pixels = 0;

    FILE *file;
    
    char name[100];
    char input_images[100] = INPUT_DIRECTORY;
    char output_images[100] = OUTPUT_DIRECTORY;

    display_menu();
    printf("Select option: ");

    menu = 0; // Must be initilized to avoid errors

    while (menu != 12)
    {

        while (scanf("%d", &menu) != 1 || menu <= 0 || menu > 12)
        {
            display_menu();
            printf("Incorrect input!\n\n");
            printf("Select option: ");
            while (getchar() != '\n')
                ;
        }

        switch (menu)
        {
        case 1:

            strcpy(input_images, INPUT_DIRECTORY);

            display_menu();
            printf("Enter the name of the file: ");
            scanf("%s", name);

            /* Bypass the file extension */
            if ((name[strlen(name) - 4]) != '.')
            {
                strcat(name, ".pgm");
            }

            strcat(input_images, name);

            file = fopen(input_images, "r");
            loaded_number_of_pixels = read_image(file, image, &width, &height, &gray);

            if (loaded_number_of_pixels != 0)
            {
                display_menu();
                fclose(file);
                is_image_loaded = true;
                printf("Image loaded successfully!\n\n");
                printf("Select option: ");

                break;
            }
            else
            {

                printf("Select option: ");

                break;
            }

        case 2:

            if (is_image_loaded == true)
            {
                strcpy(output_images, OUTPUT_DIRECTORY);

                display_menu();
                printf("Enter the name of the file to save: ");
                scanf("%s", name);
                strcat(output_images, name);
                strcat(output_images, ".pgm");
                file = fopen(output_images, "w");

                if (file != NULL)
                {
                    saved_number_of_pixels = save_image(file, image, &width, &height, &gray);
                    fclose(file);
                }

                if (saved_number_of_pixels != 0)
                {
                    display_menu();
                    printf("Image saved successfully!\n\n");
                    printf("Select option: ");
                }

                if (loaded_number_of_pixels != 0)
                {
                    display(output_images);

                    break;
                }
            }
            else
            {
                display_menu();
                printf("No image has been loaded!\n\n");
                printf("Select option: ");

                break;
            }

        case 3:

            if (is_image_loaded == true)
            {
                display_menu();
                negative(image, width, height, gray);
                printf("A negative operation was performed on the image.\n\n");
                printf("Select option: ");

                break;
            }
            else
            {
                display_menu();
                printf("No image has been loaded!\n\n");
                printf("Select option: ");

                break;
            }

        case 4:

            if (is_image_loaded == true)
            {
                display_menu();
                printf("Enter the threshold level: ");
                scanf("%d", &threshold_level);

                if (threshold_level > 0)
                {
                    display_menu();
                    thresholding(image, width, height, gray, threshold_level);
                    printf("A thresholding operation (%d%%) was performed on the image.\n\n", threshold_level);
                    printf("Select option: ");

                    break;
                }
                else
                {
                    display_menu();
                    printf("The threshold level cannot be negative or equal to zero!\n\n");
                    printf("Select option: ");

                    break;
                }
            }
            else
            {
                display_menu();
                printf("No image has been loaded!\n\n");
                printf("Select option: ");

                break;
            }

        case 5:

            if (is_image_loaded == true)
            {
                display_menu();
                printf("Enter the threshold level: ");
                scanf("%d", &threshold_level);

                if (threshold_level > 0)
                {
                    display_menu();
                    thresholding_black(image, width, height, gray, threshold_level);
                    printf("A black thresholding operation (%d%%) was performed on the image.\n\n", threshold_level);
                    printf("Select option: ");

                    break;
                }
                else
                {
                    display_menu();
                    printf("The threshold level cannot be negative or equal to zero!\n\n");
                    printf("Select option: ");

                    break;
                }
            }
            else
            {
                display_menu();
                printf("No image has been loaded!\n\n");
                printf("Select option: ");

                break;
            }

        case 6:

            if (is_image_loaded == true)
            {
                display_menu();
                printf("Enter the threshold level: ");
                scanf("%d", &threshold_level);

                if (threshold_level > 0)
                {
                    display_menu();
                    thresholding_white(image, width, height, gray, threshold_level);
                    printf("A white thresholding operation (%d%%) was performed on the image.\n\n", threshold_level);
                    printf("Select option: ");

                    break;
                }
                else
                {
                    display_menu();
                    printf("The threshold level cannot be negative or equal to zero!\n\n");
                    printf("Select option: ");

                    break;
                }
            }
            else
            {
                display_menu();
                printf("No image has been loaded!\n\n");
                printf("Select option: ");

                break;
            }

        case 7:

            if (is_image_loaded == true)
            {
                display_menu();
                printf("Enter the gammma parameter: ");
                scanf("%f", &gamma_parameter);

                if (gamma_parameter > 0)
                {
                    display_menu();
                    gamma_correction(image, width, height, gray, gamma_parameter);
                    printf("A gamma correction operation (%.1f) was performed on the image.\n\n", gamma_parameter);
                    printf("Select option: ");

                    break;
                }
                else
                {
                    display_menu();
                    printf("The gamma parameter cannot be negative or equal to zero!\n\n");
                    printf("Select option: ");

                    break;
                }
            }
            else
            {
                display_menu();
                printf("No image has been loaded!\n\n");
                printf("Select option: ");

                break;
            }

        case 8:

            if (is_image_loaded == true)
            {
                display_menu();
                printf("Enter the new white level: ");
                scanf("%d", &white);
                display_menu();
                printf("Enter the new black level: ");
                scanf("%d", &black);

                if (white > 0 && black > 0)
                {
                    display_menu();
                    change_levels(image, width, height, gray, white, black);
                    printf("A change levels operation (%d%%) (%d%%) was performed on the image.\n\n", white, black);
                    printf("Select option: ");

                    break;
                }
                else
                {
                    display_menu();
                    printf("The new white and black levels cannot be negative or equal to zero!\n\n");
                    printf("Select option: ");

                    break;
                }
            }
            else
            {
                display_menu();
                printf("No image has been loaded!\n\n");
                printf("Select option: ");

                break;
            }

        case 9:

            if (is_image_loaded == true)
            {
                display_menu();
                contouring(image, width, height, gray);
                printf("A countouring operation was performed on the image.\n\n");
                printf("Select option: ");

                break;
            }
            else
            {
                display_menu();
                printf("No image has been loaded!\n\n");
                printf("Select option: ");

                break;
            }

        case 10:

            if (is_image_loaded == true)
            {
                display_menu();
                horizontal_blur(image, width, height, gray);
                printf("A horizontal blur operation was performed on the image.\n\n");
                printf("Select option: ");

                break;
            }
            else
            {
                display_menu();
                printf("No image has been loaded!\n\n");
                printf("Select option: ");

                break;
            }

        case 11:

            if (is_image_loaded == true)
            {
                display_menu();
                vertical_blur(image, width, height, gray);
                printf("A vertical blur operation was performed on the image.\n\n");
                printf("Select option: ");

                break;
            }
            else
            {
                display_menu();
                printf("No image has been loaded!\n\n");
                printf("Select option: ");

                break;
            }

        case 12:

            system("clear");

            break;
        }
    }

    return 0;
}