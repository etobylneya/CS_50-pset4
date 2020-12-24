#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {
            int avg = round((image[i][k].rgbtBlue + image[i][k].rgbtGreen + image[i][k].rgbtRed) / 3);
            image[i][k].rgbtBlue = avg;
            image[i][k].rgbtGreen = avg;
            image[i][k].rgbtRed = avg;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width / 2; k++)
        {
            RGBTRIPLE temp;
            temp = image[i][k];
            image[i][k] = image[i][(width - 1) - k];
            image[i][(width - 1) - k] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {
            if (i == 0 && k == 0)
            {
                image[i][k].rgbtBlue = round((image[i][k].rgbtBlue + image[i][k + 1].rgbtBlue + image[i + 1][k].rgbtBlue + image[i + 1][k + 1].rgbtBlue) / 4);
                image[i][k].rgbtGreen = round((image[i][k].rgbtGreen + image[i][k + 1].rgbtGreen + image[i + 1][k].rgbtGreen + image[i + 1][k + 1].rgbtGreen) / 4);
                image[i][k].rgbtRed = round((image[i][k].rgbtRed + image[i][k + 1].rgbtRed + image[i + 1][k].rgbtRed + image[i + 1][k + 1].rgbtRed) / 4);
            }
            else if (i == 0 && k == width - 1)
            {
                image[i][k].rgbtBlue = round((image[i][k].rgbtBlue + image[i][k - 1].rgbtBlue + image[i + 1][k].rgbtBlue + image[i + 1][k - 1].rgbtBlue) / 4);
                image[i][k].rgbtGreen = round((image[i][k].rgbtGreen + image[i][k - 1].rgbtGreen + image[i + 1][k].rgbtGreen + image[i + 1][k - 1].rgbtGreen) / 4);
                image[i][k].rgbtRed = round((image[i][k].rgbtRed + image[i][k - 1].rgbtRed + image[i + 1][k].rgbtRed + image[i + 1][k - 1].rgbtRed) / 4);
            }
            else if (i == 0 && 0 < k < width - 1)
            {
                image[i][k].rgbtBlue = round((image[i][k].rgbtBlue + image[i][k - 1].rgbtBlue + image[i][k + 1].rgbtBlue + image[i + 1][k].rgbtBlue + image[i + 1][k - 1].rgbtBlue + image[i + 1][k + 1].rgbtBlue) / 6);
                image[i][k].rgbtGreen = round((image[i][k].rgbtGreen + image[i][k - 1].rgbtGreen + image[i][k + 1].rgbtGreen + image[i + 1][k].rgbtGreen + image[i + 1][k - 1].rgbtGreen + image[i + 1][k + 1].rgbtGreen) / 6);
                image[i][k].rgbtRed = round((image[i][k].rgbtRed + image[i][k - 1].rgbtRed + image[i][k + 1].rgbtRed + image[i + 1][k].rgbtRed + image[i + 1][k - 1].rgbtRed + image[i + 1][k + 1].rgbtRed) / 6);
            }
            else if (i != 0 && k == 0)
            {
                image[i][k].rgbtBlue = round((image[i][k].rgbtBlue + image[i - 1][k].rgbtBlue + image[i - 1][k + 1].rgbtBlue + image[i][k + 1].rgbtBlue + image[i + 1][k].rgbtBlue + image[i + 1][k + 1].rgbtBlue) / 6);
                image[i][k].rgbtGreen = round((image[i][k].rgbtGreen + image[i - 1][k].rgbtGreen + image[i - 1][k + 1].rgbtGreen + image[i][k + 1].rgbtGreen + image[i + 1][k].rgbtGreen + image[i + 1][k + 1].rgbtGreen) / 6);
                image[i][k].rgbtRed = round((image[i][k].rgbtRed + image[i - 1][k].rgbtRed + image[i - 1][k + 1].rgbtRed + image[i][k + 1].rgbtRed + image[i + 1][k].rgbtRed + image[i + 1][k + 1].rgbtRed) / 6);
            }
            else if (i != 0 && k == width - 1)
            {
                image[i][k].rgbtBlue = round((image[i][k].rgbtBlue + image[i  -1][k].rgbtBlue + image[i - 1][k - 1].rgbtBlue + image[i][k - 1].rgbtBlue + image[i + 1][k].rgbtBlue + image[i + 1][k - 1].rgbtBlue) / 6);
                image[i][k].rgbtGreen = round((image[i][k].rgbtGreen + image[i  -1][k].rgbtGreen + image[i - 1][k - 1].rgbtGreen + image[i][k - 1].rgbtGreen + image[i + 1][k].rgbtGreen + image[i + 1][k - 1].rgbtGreen) / 6);
                image[i][k].rgbtRed = round((image[i][k].rgbtRed + image[i  -1][k].rgbtRed + image[i - 1][k - 1].rgbtRed + image[i][k - 1].rgbtRed + image[i + 1][k].rgbtRed + image[i + 1][k - 1].rgbtRed) / 6);
            }
            else if (i != 0 && i != height - 1 && k != 0 && k != width - 1)
            {
                image[i][k].rgbtBlue = round((image[i][k].rgbtBlue + image[i - 1][k - 1].rgbtBlue + image[i - 1][k].rgbtBlue + image[i - 1][k + 1].rgbtBlue + image[i][k - 1].rgbtBlue + image[i][k + 1].rgbtBlue + image[i + 1][k - 1].rgbtBlue + image[i + 1][k].rgbtBlue + image[i + 1][k + 1].rgbtBlue) / 9);
                image[i][k].rgbtGreen = round((image[i][k].rgbtGreen + image[i - 1][k - 1].rgbtGreen + image[i - 1][k].rgbtGreen + image[i - 1][k + 1].rgbtGreen + image[i][k - 1].rgbtGreen + image[i][k + 1].rgbtGreen + image[i + 1][k - 1].rgbtGreen + image[i + 1][k].rgbtGreen + image[i + 1][k + 1].rgbtGreen) / 9);
                image[i][k].rgbtRed = round((image[i][k].rgbtRed + image[i - 1][k - 1].rgbtRed + image[i - 1][k].rgbtRed + image[i - 1][k + 1].rgbtRed + image[i][k - 1].rgbtRed + image[i][k + 1].rgbtRed + image[i + 1][k - 1].rgbtRed + image[i + 1][k].rgbtRed + image[i + 1][k + 1].rgbtRed) / 9);

            }
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {
            if (i != 0 && i != height - 1 && k != 0 && k != width - 1)
            {
                //Blue
                int Gx, Gy;
                Gx = ((image[i - 1][k - 1].rgbtBlue * (-1)) + (image[i - 1][k].rgbtBlue * 0) + (image[i - 1][k + 1].rgbtBlue * 1) + (image[i][k - 1].rgbtBlue * (-2)) + (image[i][k].rgbtBlue * 0) + (image[i][k + 1].rgbtBlue * 2) + (image[i + 1][k - 1].rgbtBlue * (-1)) + (image[i + 1][k].rgbtBlue * 0) + (image[i + 1][k + 1].rgbtBlue * 1));
                Gy = ((image[i - 1][k - 1].rgbtBlue * (-1)) + (image[i - 1][k].rgbtBlue * (-2)) + (image[i - 1][k + 1].rgbtBlue * (-1)) + (image[i][k - 1].rgbtBlue * 0) + (image[i][k].rgbtBlue * 0) + (image[i][k + 1].rgbtBlue * 0) + (image[i + 1][k - 1].rgbtBlue * 1) + (image[i + 1][k].rgbtBlue * 2)+ (image[i + 1][k + 1].rgbtBlue * 1));
                double res;
                res = sqrt((Gx*Gx) + (Gy*Gy));
                //image[i][k].rgbtBlue = round(res);
                if (res <= 255)
                {
                    image[i][k].rgbtBlue = round(res);
                }
                else
                {
                    image[i][k].rgbtBlue = 255;
                }


                //Green
                Gx = (image[i - 1][k - 1].rgbtGreen * (-1) + image[i - 1][k].rgbtGreen * 0 + image[i - 1][k + 1].rgbtGreen * 1 + image[i][k - 1].rgbtGreen * (-2) + image[i][k].rgbtGreen * 0 + image[i][k + 1].rgbtGreen * 2 + image[i + 1][k - 1].rgbtGreen * (-1) + image[i + 1][k].rgbtGreen * 0 + image[i + 1][k + 1].rgbtGreen * 1);
                Gy = (image[i - 1][k - 1].rgbtGreen * (-1) + image[i - 1][k].rgbtGreen * (-2) + image[i - 1][k + 1].rgbtGreen * (-1) + image[i][k - 1].rgbtGreen * 0 + image[i][k].rgbtGreen * 0 + image[i][k + 1].rgbtGreen * 0 + image[i + 1][k - 1].rgbtGreen * 1 + image[i + 1][k].rgbtGreen * 2 + image[i + 1][k + 1].rgbtGreen * 1);
                res = sqrt((Gx*Gx) + (Gy*Gy));
                //image[i][k].rgbtGreen = round(res);
                
                if (res <= 255)
                {
                    image[i][k].rgbtGreen = round(res);
                }
                else
                {
                    image[i][k].rgbtGreen = 255;
                }


                //Red
                Gx = (image[i - 1][k - 1].rgbtRed * (-1) + image[i - 1][k].rgbtRed * 0 + image[i - 1][k + 1].rgbtRed * 1 + image[i][k - 1].rgbtRed * (-2) + image[i][k].rgbtRed * 0 + image[i][k + 1].rgbtRed * 2 + image[i + 1][k - 1].rgbtRed * (-1) + image[i + 1][k].rgbtRed * 0 + image[i + 1][k + 1].rgbtRed * 1);
                Gy = (image[i - 1][k - 1].rgbtRed * (-1) + image[i - 1][k].rgbtRed * (-2) + image[i - 1][k + 1].rgbtRed * (-1) + image[i][k - 1].rgbtRed * 0 + image[i][k].rgbtRed * 0 + image[i][k + 1].rgbtRed * 0 + image[i + 1][k - 1].rgbtRed * 1 + image[i + 1][k].rgbtRed * 2 + image[i + 1][k + 1].rgbtRed * 1);
                res = sqrt((Gx*Gx) + (Gy*Gy));
                //image[i][k].rgbtGreen = round(res);
                if (res <= 255)
                {
                    image[i][k].rgbtRed = round(res);
                }
                else
                {
                    image[i][k].rgbtRed = 255;
                }

            }
        }
    }
    return;
}
