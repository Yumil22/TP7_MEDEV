#include "compression_rlc.h"

std::string compressionrlc(cv::Mat im) {
	std::vector<int> v = lecture(im);
	std::string s = comp(v);
	return s;
}

std::vector<int> lecture(cv::Mat im) {
	//On sait que notre matrice im est de taille 8*8
	
	//On cree notre vecteur
	std::vector<int> v = {};

	int i = 0;
	int j = 0;

	v.push_back(im.at<cv::Vec3b>(i, j)[0]);
	v.push_back(im.at<cv::Vec3b>(i, j)[1]);
	v.push_back(im.at<cv::Vec3b>(i, j)[2]);
	i = 1;
	bool up = true;

	//Boucle de lecture en zig zag
	while ((i != 0) || (j != 7)) {
		if (up && i != 0) {
			v.push_back(im.at<cv::Vec3b>(i, j)[0]);
			v.push_back(im.at<cv::Vec3b>(i, j)[1]);
			v.push_back(im.at<cv::Vec3b>(i, j)[2]);
			i--;
			j++;
		}

		if (up && i == 0) {
			v.push_back(im.at<cv::Vec3b>(i, j)[0]);
			v.push_back(im.at<cv::Vec3b>(i, j)[1]);
			v.push_back(im.at<cv::Vec3b>(i, j)[2]);
			j++;
			up = false;
		}

		if (!up && j != 0) {
			v.push_back(im.at<cv::Vec3b>(i, j)[0]);
			v.push_back(im.at<cv::Vec3b>(i, j)[1]);
			v.push_back(im.at<cv::Vec3b>(i, j)[2]);
			i++;
			j--;
		}

		if (!up && j == 0) {
			v.push_back(im.at<cv::Vec3b>(i, j)[0]);
			v.push_back(im.at<cv::Vec3b>(i, j)[1]);
			v.push_back(im.at<cv::Vec3b>(i, j)[2]);
			i++;
			up = true;
		}
	}

	v.push_back(im.at<cv::Vec3b>(i, j)[0]);
	v.push_back(im.at<cv::Vec3b>(i, j)[1]);
	v.push_back(im.at<cv::Vec3b>(i, j)[2]);
	i++;
	up = false;

	while ((i != 7) || (j != 7)) {
		if (!up && i != 7) {
			v.push_back(im.at<cv::Vec3b>(i, j)[0]);
			v.push_back(im.at<cv::Vec3b>(i, j)[1]);
			v.push_back(im.at<cv::Vec3b>(i, j)[2]);
			i++;
			j--;
		}

		if (!up && i == 7) {
			v.push_back(im.at<cv::Vec3b>(i, j)[0]);
			v.push_back(im.at<cv::Vec3b>(i, j)[1]);
			v.push_back(im.at<cv::Vec3b>(i, j)[2]);
			j++;
			up = true;
		}

		if (up && j != 7) {
			v.push_back(im.at<cv::Vec3b>(i, j)[0]);
			v.push_back(im.at<cv::Vec3b>(i, j)[1]);
			v.push_back(im.at<cv::Vec3b>(i, j)[2]);
			i--;
			j++;
		}

		if (up && j == 7) {
			v.push_back(im.at<cv::Vec3b>(i, j)[0]);
			v.push_back(im.at<cv::Vec3b>(i, j)[1]);
			v.push_back(im.at<cv::Vec3b>(i, j)[2]);
			i++;
			up = false;
		}
	}

	return v;
}

std::string comp(std::vector<int> v) {
	std::string s = "";
	int size = 64 * 3; //64 de longueur et 3 canaux
	int compte = 1;
	int memory = v[0];
	for (int i = 1 ; i < size; i++) {
		if (v[i] == memory) {
			compte++;
		}

		else {
			if (compte == 1) {
				s = s + std::to_string(memory);
				s = s + ",";
				memory = v[i];
			}
			else {
				s = s + std::to_string(memory);
				s = s + ":";
				s = s + std::to_string(compte);
				s = s + ",";
				memory = v[i];
				compte = 1;
			}
		}
	}
	return s;
}

std::vector<std::string> compresstot(std::vector<cv::Mat> Vecim) {
	std::vector<std::string> vec = {};
	std::string s;
	for (int i = 0; i < std::size(Vecim); i++) {
		s = compressionrlc(Vecim[i]);
		vec.push_back(s);
	}
	return vec;
}