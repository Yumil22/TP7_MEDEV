#include "compression_rlc.h"

string compressionrlc(cv::Mat im) {
	vector<int> v = lecture(im);
	string s = comp(v);
	return s;
}

vector<int> lecture(cv::Mat im) {
	//On sait que notre matrice im est de taille 8*8
	
	//On cree notre vecteur
	vector<int> v = {};

	int i = 0;
	int j = 0;

	v.push_back(im.at<uchar>(i, j)[0]);
	v.push_back(im.at<uchar>(i, j)[1]);
	v.push_back(im.at<uchar>(i, j)[2]);
	i = 1;
	bool up = true;

	while ((i != 0) || (j != 7)) {
		if (up && i != 0) {
			v.push_back(im.at<uchar>(i, j)[0]);
			v.push_back(im.at<uchar>(i, j)[1]);
			v.push_back(im.at<uchar>(i, j)[2]);
			i--;
			j++;
		}

		if (up && i == 0) {
			v.push_back(im.at<uchar>(i, j)[0]);
			v.push_back(im.at<uchar>(i, j)[1]);
			v.push_back(im.at<uchar>(i, j)[2]);
			j++;
			up = false;
		}

		if (!up && j != 0) {
			v.push_back(im.at<uchar>(i, j)[0]);
			v.push_back(im.at<uchar>(i, j)[1]);
			v.push_back(im.at<uchar>(i, j)[2]);
			i++;
			j--;
		}

		if (!up && j == 0) {
			v.push_back(im.at<uchar>(i, j)[0]);
			v.push_back(im.at<uchar>(i, j)[1]);
			v.push_back(im.at<uchar>(i, j)[2]);
			i++;
			up = true;
		}
	}

	v.push_back(im.at<uchar>(i, j)[0]);
	v.push_back(im.at<uchar>(i, j)[1]);
	v.push_back(im.at<uchar>(i, j)[2]);
	i++;
	up = false;

	while ((i != 7) || (j != 7)) {
		if (!up && i != 7) {
			v.push_back(im.at<uchar>(i, j)[0]);
			v.push_back(im.at<uchar>(i, j)[1]);
			v.push_back(im.at<uchar>(i, j)[2]);
			i++;
			j--;
		}

		if (!up && i == 7) {
			v.push_back(im.at<uchar>(i, j)[0]);
			v.push_back(im.at<uchar>(i, j)[1]);
			v.push_back(im.at<uchar>(i, j)[2]);
			j++;
			up = true;
		}

		if (up && j != 7) {
			v.push_back(im.at<uchar>(i, j)[0]);
			v.push_back(im.at<uchar>(i, j)[1]);
			v.push_back(im.at<uchar>(i, j)[2]);
			i--;
			j++;
		}

		if (up && j == 7) {
			v.push_back(im.at<uchar>(i, j)[0]);
			v.push_back(im.at<uchar>(i, j)[1]);
			v.push_back(im.at<uchar>(i, j)[2]);
			i++;
			up = false;
		}
	}

	return v;
}

string comp(vector<int> v) {
	string s = "";
	int size = 64 * 3; //64 de longueur et 3 canaux
	int compte = 1;
	int memory = v[0];
	for (int i = 1 ; i < size; i++) {
		if (v[i] == memory) {
			compte++;
		}

		else {
			if (compte == 1) {
				s = s + (string)memory;
				s = s + ",";
				memory = v[i];
			}
			else {
				s = s + (string)memory;
				s = s + ":";
				s = s + (string)compte;
				s = s + ",";
				memory = v[i];
				compte = 1;
			}
		}
	}
	return s;
}