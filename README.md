# Image Processing 1

Image Processing 1 is a project I realized in the first semester of my studies within the Programming Principles course
at the Wroclaw University of Technology in the field of Control Engineering and Robotics. The main purpose of a program is
to perform image processing operations on grayscale images in PGM format, which are represented in the program as two-dimensional static arrays.

## Table of Contents

  - [Features](#features)
  - [Screenshots](#screenshots)
  - [Setup](#setup)
  - [Usage](#usage)
  - [Concepts I Learned](#concepts-i-learned)

## Features

- Load PGM images with comment skipping,
- Save and display the processed image with an external program (ImageMagick),
- Perform following image processing operations:
  - negative,
  - thresholding,
  - thresholding black,
  - thresholding white,
  - gamma correction,
  - change levels,
  - contouring,
  - horizontal and vertical blur.


## Screenshots

Screenshots below represent results of chosen image processing operations.
On the left is the original image and then processed.

---

### Negative

![screenshot1](./screenshots/negative.png "Negative")

---

### Contouring

![screenshot2](./screenshots/contouring.png "Contouring")

---

### Changing levels

Images processed for the new levels black 20% white 80% (second image) and black 40% white 60% (third image).

![screenshot3](./screenshots/levels.png "Changing_levels")

---

### Thresholding

Images processed for given threshold levels 20% (second image), 50% (third image), 80% (fourth image).

![screenshot4](./screenshots/threshold.png "Thresholding")

---


## Setup

Prerequisites:
* Installed CMake *(minimum VERSION 3.0)*,
* Installed ImageMagick.

Clone repository:

    git clone https://github.com/maciejkaniewski/Image_Processing_1.git

Create `build` directory and launch `CMake`:

    cd Image_Processing_1
    mkdir build
    cd build
    cmake ..

The above operation also creates the `images_results` folder.

Run `make` command and execute the program:

    make
    ./Image_Processing_1 

## Usage

After executing a program, the text menu will show up in the terminal:

    Image processing:
    
     1. Load image
     2. Save and display image
     3. Negative
     4. Thresholding
     5. Thresholding black
     6. Thresholding white
     7. Gamma correction
     8. Change levels
     9. Contouring
    10. Horizontal blur
    11. Vertical blur
    12. End program
    
    Select option:

By entering the numbers that are located next to each option, the options will be activated.

First, you need to load an image with *1st option*. The folder from which the program loads images is the `images` folder.
There is no need to provide the file extension, for example if you want to load the `pooh.pgm` file, you just need to give 
the name itself, i.e. `pooh`. You can then execute any processing operation. Each operation informs about its successful 
completion with an appropriate message. Then you can save the image with a name of your choice and display
it with *2nd option*. The program itself adds the `.pgm` extension to the name. The folder where the images are saved is the `images_results` folder. 
Both the input and output folders can be changed in the `defines.h` file:

```C
#ifndef DEFINES_H_
#define DEFINES_H_

#define MAX 512          /* Maximum size of a loaded image */
#define LINE_LENGTH 1024 /* The length of the auxiliary buffers */
#define PGM_LINIE 70     /* Maximum line length in a PGM image, normally 70, for tests 20 */
#define INPUT_DIRECTORY "../images/"
#define OUTPUT_DIRECTORY "../images_results/"

#endif // DEFINES_H_
```
If you want to re-execute the processing operation, you must reload the image, otherwise, the processing operation will be performed on the already processed image.


## Concepts I Learned

- Basic C language instructions,
- Using pointers to communicate between functions,
- File operations,
- CMake basics.
