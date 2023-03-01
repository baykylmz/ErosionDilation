# ErosionDilation

Applying Dilation and Erosion operations, which fall under the category of morphological operations from Image Processing techniques, on a 512x512 picture by writing inline assembly code within the Erosion() and Dilation() functions.

- Pictures are represented as matrices. However, within the Erosion() and Dilation() functions, the picture you need to process is kept as a string with consecutive lines added one after the other. In the code you should perform your operations through the image_org array.
- The prototypes of Erosion() and Dilation() functions are as shown in the picture below. The first parameter gives the size (width * height) of the image[][] matrix (It is known that the image is a square matrix). The second parameter gives the filter size you need to use for erosion and dilation, and the third parameter gives the address of the image_org[] array in memory.
