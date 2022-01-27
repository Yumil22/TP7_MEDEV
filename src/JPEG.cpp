
#include <iostream>


#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


// no idea why on the virtual box the keycode is completely wrong
#define ESC_KEY      27
#define ESC_KEY_VM   1048603 // should be 27

#define Q_KEY        113
#define Q_KEY_VM     1048689 // should be 113

using namespace std;
using namespace cv;

using namespace std;

int main(int argc, char* argv[])
{
	// the OpenCV data structure storing the image
	Mat im;

	// the (default) name of the image file
	String imName = "../images/monarch.png";

	// Reading the image   
	im = imread(imName);

	if (!im.data || im.empty() || (im.rows == 0) || (im.cols == 0)) {
		cout << "Could not load image !" << endl;
		cout << "Exiting now..." << endl;
		return 1;
	}


	// Displaying the loaded image in the named window
	imshow("Original image", im);


	// Waiting for the user to press ESCAPE before exiting the application	
	int key = 0;

	// you may need to change ESC_KEY to ESC_KEY_VM
	// and Q_KEY to Q_KEY_VM
	while ((key != ESC_KEY) && (key != Q_KEY)) {
		key = waitKey(1);
	}

	destroyAllWindows();

	return 0;
}