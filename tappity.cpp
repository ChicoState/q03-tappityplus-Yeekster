#include "tappity.h"
#include <cmath>
using std::round;
/**
 * Class for tappity
**/

//Constructor sets the reference phrase
tappity::tappity(std::string reference) : ref_string(reference), in_string(""){}

//Provide the input to be compared to the reference. Before this 
//function is called, the input should be considered an empty string
void tappity::entry(std::string input){
  in_string = input;
}

//Compares the length of the reference to that of the input and
//returns the absolute value of the difference, or 0 if they are the
//same length
int tappity::length_difference(){
  return abs(in_string.length() - ref_string.length());
}

//Compares the content of the reference to that of the input and
//calculates the accuracy of matching characters. If the two strings
//are identical, accuracy should be 100. However, for each 
//corresponding character that does not match in the same location,
//the percentage of corresponding characters should be returned.
//For example, if the reference and input have 10 letters and the input
//matches 8 of the corresponding reference characters, the function 
//should return 80. When input does not have the same number of
//characters as the reference, the accuracy should represent the percent
//of matching characters between the shorter and longer strings. For
//example, if one string has 8 characters matching the corresponding
//locations in another string that has 16 characters, the accuracy is 50.
double tappity::accuracy(){
  int max = (ref_string.length() >= in_string.length()) ? ref_string.length() : in_string.length();
  int min = (ref_string.length() >= in_string.length()) ? in_string.length() : ref_string.length();
  int pts = 0;
  if (max == 0)
    max = -1;
  for (int i = 0; i < max; i++)
    if (min > i)                            //If the length of the min string is greater than the index
      if (ref_string[i] == in_string[i])    //If the strings match 
        pts++;                              //Add a point

  double score = double(pts)/double(max) * 100;
  int final_score = round(score);
  return (max == -1) ? 100 : final_score;
}
