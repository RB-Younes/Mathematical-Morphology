#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include "tpMorphology.h"

using namespace cv;

int main()
{
    cv::Mat structEle = (cv::Mat_<float>(3, 3) <<
        0.0f, 1.0f, 0.0f,
        1.0f, 1.0f, 1.0f,
        0.0f, 1.0f, 0.0f);


    std::string image_path = samples::findFile("noidea.jpg");
    Mat img = imread(image_path, IMREAD_GRAYSCALE);
    if (img.empty())
    {
        std::cout << "Could not read the image: " << image_path << std::endl;
        return 1;
    }
    //convert to float
    if (img.type() != CV_32F) {
        img.convertTo(img, CV_32F);
    }

    Mat res = morphologicalGradient(img, structEle);


    // Normaliser les valeurs de l'image dans la plage [0, 1]
    normalize(img, img, 0.0, 1.0, NORM_MINMAX);
    normalize(res, res, 0.0, 1.0, NORM_MINMAX);
    imshow("Display window1", img);

    imshow("Display window2", res);



    int k = waitKey(0); // Wait for a keystroke in the window
    int k1 = waitKey(0); // Wait for a keystroke in the window







}