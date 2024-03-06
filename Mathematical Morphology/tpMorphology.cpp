#include "tpMorphology.h"
#include <cmath>
#include <algorithm>
#include <tuple>
#include <limits>
#include "common.h"
using namespace cv;
using namespace std;


/**
    Compute a median filter of the input float image.
    The filter window is a square of (2*size+1)*(2*size+1) pixels.

    Values outside image domain are ignored.

    The median of a list l of n>2 elements is defined as:
     - l[n/2] if n is odd 
     - (l[n/2-1]+l[n/2])/2 is n is even 
*/
Mat median(Mat image, int size)
{
    Mat res = image.clone();
    assert(size>0);
    /********************************************
                YOUR CODE HERE
    *********************************************/
    int rows = image.rows;
    int cols = image.cols;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // Extract pixel values in the window
            std::vector<float> windowValues;
            for (int m = i - size; m <= i + size; m++) {
                for (int n = j - size; n <= j + size; n++) {
                    if (m >= 0 && m < rows && n >= 0 && n < cols) {
                        windowValues.push_back(image.at<float>(m, n));
                    }
                }
            }

            std::sort(windowValues.begin(), windowValues.end());

            int n = windowValues.size();
            float medianValue;
            if (n % 2 == 0) {
                medianValue = (windowValues[n / 2 - 1] + windowValues[n / 2]) / 2.0f;
            }
            else {
                medianValue = windowValues[n / 2];
            }

            res.at<float>(i, j) = medianValue;
        }
    }
    /********************************************
                END OF YOUR CODE
    *********************************************/
    return res;
}


/**
    Compute the dilation of the input float image by the given structuring element.
     Pixel outside the image are supposed to have value 0
*/
Mat dilate(Mat image, Mat structuringElement)
{
  
    /********************************************
                YOUR CODE HERE
    *********************************************/

    int rows = image.rows;
    int cols = image.cols;
    Mat res = Mat::zeros(rows, cols, CV_32F);


    int size = (structuringElement.rows - 1) / 2;


    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; ++j) 
        {
            std::vector<float> Values;
            for (int m = i - size; m <= i + size; m++) {
                for (int n = j - size; n <= j + size; n++) {
                    if (m >= 0 && m < rows && n >= 0 && n < cols) {
                        // Check if the structuring element matches at this position
                        if (structuringElement.at<float>(m - (i - size), n - (j - size)) != 0.0f)
                        {
                            Values.push_back(image.at<float>(m, n));
                        }
                    }
                }
            }

            std::sort(Values.begin(), Values.end());
            int n = Values.size();
            res.at<float>(i, j) = Values[n-1];
        }
    }
     
    /********************************************
                END OF YOUR CODE
    *********************************************/
    return res;
}


/**
    Compute the erosion of the input float image by the given structuring element.
    Pixel outside the image are supposed to have value 1.
*/
Mat erode(Mat image, Mat structuringElement)
{
    Mat res = image.clone();
    /********************************************
                YOUR CODE HERE
        hint : 1 line of code is enough
    *********************************************/
    int rows = image.rows;
    int cols = image.cols;

    int size = (structuringElement.rows - 1) / 2;


    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; ++j)
        {
            std::vector<float> Values;
            for (int m = i - size; m <= i + size; m++) {
                for (int n = j - size; n <= j + size; n++) {
                    if (m >= 0 && m < rows && n >= 0 && n < cols) {
                        // Check if the structuring element matches at this position
                        if (structuringElement.at<float>(m - (i - size), n - (j - size)) != 0.0f)
                        {
                            Values.push_back(image.at<float>(m, n));
                        }
                    }
                }
            }

            std::sort(Values.begin(), Values.end());
            int n = Values.size();
            res.at<float>(i, j) = Values[0];
        }
    }
    /********************************************
                END OF YOUR CODE
    *********************************************/
    return res;
}


/**
    Compute the opening of the input float image by the given structuring element.
*/
Mat open(Mat image, Mat structuringElement)
{

    Mat res = Mat::zeros(1,1,CV_32FC1);
    /********************************************
                YOUR CODE HERE
        hint : 1 line of code is enough
    *********************************************/
    
    /********************************************
                END OF YOUR CODE
    *********************************************/
    return res;
}


/**
    Compute the closing of the input float image by the given structuring element.
*/
Mat close(Mat image, Mat structuringElement)
{

    Mat res = Mat::zeros(1,1,CV_32FC1);
    /********************************************
                YOUR CODE HERE
        hint : 1 line of code is enough
    *********************************************/
    
    /********************************************
                END OF YOUR CODE
    *********************************************/
    return res;
}


/**
    Compute the morphological gradient of the input float image by the given structuring element.
*/
Mat morphologicalGradient(Mat image, Mat structuringElement)
{

    Mat res = Mat::zeros(1,1,CV_32FC1);
    /********************************************
                YOUR CODE HERE
        hint : 1 line of code is enough
    *********************************************/
    
    /********************************************
                END OF YOUR CODE
    *********************************************/
    return res;
}

