/************************************/
//									//
//	Author: Kevin Phan				//
//	Last modified: Feb. 6 2023      //
//	Version: 1.0					//
//									//
/************************************/

#ifndef WEATHERAPP_H
#define WEATHERAPP_H
#include <iostream>
struct Weather
{
	double temp{}; 
	std::string weatherType{};
	double precipitation{};
	std::string saltTrucks{"0"};
	std::string sandTrucks{"0"};
	std::string preUnit{};
	int plowTrucks{};
	int exitFlag{};
};
void promptUser(char command, Weather& w);
void mixedWeather(Weather& w);
void mixedWeatherTemp(Weather& w);
void snowWeather(Weather& w);
void getWeatherTemp(Weather& w);
void iceWeather(Weather& w);

#endif 