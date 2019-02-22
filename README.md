# Dithering project

* Language : C++
* Image Processing Library : OpenCV

## Setup

Please download OpenCV and place the folder under Dithering\Dithering\vendor, you only need following folders : 

  1. build\include
  2. build\x64

Or you can just leave it all in there, it can still works.

You might also need to place opencv_world401[d].dll in the project directory, if it's not there.

## Current Implementations

1. FloydSteinberg
2. <TODO...>

## TODO

* External File Control : 
  * Use kernel matrix files to represent the weight of quant error to be added to each neighbor pixel.
```
Floyd-Steinberg Dithering

           X    7/16
   3/16  5/16   1/16

Possible Format :
  (x_offset, y_offset, weight)

So for Floyd-Steinberg Dithering, it'll be :

   1, 0, 7
  -1, 1, 3
   0, 1, 5
   1, 1, 1

> divisor can be sumed in the program by adding all the weights

```