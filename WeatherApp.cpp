/************************************/
//									//
//	Author: Kevin Phan				//
//	Last modified: Feb. 6 2023      //
//	Version: 1.0					//
//									//
/************************************/

#include <iostream>
#include "WeatherApp.h"

using namespace std;
void snowWeather(Weather& w)
{
	bool valid = false;
	cout << "Enter the precipitation: ";

	do
	{
		cin >> w.precipitation;
		if (w.precipitation >= 42.5)
		{
			cout << "Calling the army. Please standby..." << endl;
			w.plowTrucks = 0;
			w.saltTrucks = "0";
			w.sandTrucks = "0";
			valid = true;
		}
		else if (w.precipitation <= 2.0)
		{
			getWeatherTemp(w);
			if (w.temp > -7)
			{
				cout << "No action needed" << endl;
				w.plowTrucks = 0;
				w.saltTrucks = "0";
				w.sandTrucks = "0";
			}
			else
			{
				if (w.temp < -15)
				{
					w.sandTrucks = "1 light";
					w.saltTrucks = "0";
				}
				else
				{
					w.saltTrucks = "1 light";
					w.sandTrucks = "0";
				}
			}
			w.plowTrucks = 0;
			valid = true;
		}
		else if (w.precipitation > 15.5 && w.precipitation < 42.5)
		{
			getWeatherTemp(w);
			if (w.temp > -7)
			{
				w.plowTrucks = 2;
				w.sandTrucks = "0";
				w.saltTrucks = "0";
			}
			else
			{
				if (w.temp < -15)
				{
					w.sandTrucks = "1 normal";
					w.saltTrucks = "0";
				}
				else
				{
					w.saltTrucks = "1 normal";
					w.sandTrucks = "0";
				}
				w.plowTrucks = 0;
			}
			valid = true;
		}
		else if (w.precipitation >= 5.75 && w.precipitation < 15.5)
		{
			getWeatherTemp(w);
			if (w.temp < -15)
			{
				w.plowTrucks = 1;
				w.sandTrucks = "1 normal";
			}
			else if (w.temp > -7)
			{
				w.plowTrucks = 1;
				w.sandTrucks = "0";
			}
			else
			{
				w.plowTrucks = 1;
				w.sandTrucks = "1 normal";
			}
			w.saltTrucks = "0";
			valid = true;
		}
		else
		{
			getWeatherTemp(w);
			if (w.temp < -15)
			{
				w.saltTrucks = "1 normal";
				w.sandTrucks = "0";
			}
			else
			{
				w.sandTrucks = "1 normal";
				w.saltTrucks = "0";
			}
			w.plowTrucks = 0;
		}
	} while (valid == false);
}

void getWeatherTemp(Weather& w)
{
	cout << "Enter the temperature: ";
	cin >> w.temp;
}

void iceWeather(Weather& w)
{
	bool valid = false;
	cout << "Enter the precipitation: ";

	do
	{
		cin >> w.precipitation;
		if (w.precipitation > 17)
		{
			cout << "Calling the army. Please standby..." << endl;
			w.plowTrucks = 0;
			w.saltTrucks = "0";
			w.sandTrucks = "0";
			valid = true;
		}
		else if (w.precipitation <= 3)
		{
		
			cout << "No action needed" << endl;
			w.plowTrucks = 0;
			w.saltTrucks = "0";
			w.sandTrucks = "0";
		}
		else if (w.precipitation <= 5.5 && w.precipitation > 3)
		{
			getWeatherTemp(w);
			if (w.temp > -7)
			{
				cout << "No action needed" << endl;
				w.saltTrucks = "0";
				w.sandTrucks = "0";
			}
			else
			{
				if (w.temp < 15)
				{
					w.saltTrucks = "0";
					w.sandTrucks = "1 normal";
				}
				else
				{
					w.sandTrucks = "0";
					w.saltTrucks = "1 normal";
				}
			}
			w.plowTrucks = 0;
			valid = true;
		}
		else 
		{
			getWeatherTemp(w);
			if (w.temp > 7)
			{
				w.saltTrucks = "1 heavy";
				w.sandTrucks = "0";
			}
			else
			{
				if (w.temp < 15)
				{
					w.sandTrucks = "2 heavy";
					w.saltTrucks = "0";
				}
				else
				{
					w.saltTrucks = "2 heavy";
					w.sandTrucks = "0";
				}
			}
			w.plowTrucks = 0;
			valid = true;
		}
	} while (valid == false);
}

void mixedWeather(Weather& w)
{
	bool valid = false;
	cout << "Enter the precipitation: ";

	do
	{
		cin >> w.precipitation;
		if (w.precipitation > 40)
		{
			cout << "Calling the army. Please standby..." << endl;
			w.plowTrucks = 0;
			w.saltTrucks = "0";
			w.sandTrucks = "0";
			valid = true;
		}
		else if (w.precipitation <= 3.5)
		{
			cout << "No action needed" << endl;
			w.plowTrucks = 0;
			w.saltTrucks = "0";
			w.sandTrucks = "0";
			valid = true;
		}
		else
		{
			if (w.precipitation <= 16.5)
			{
				w.plowTrucks = 1;
				mixedWeatherTemp(w);
				valid = true;
			}
			else
			{
				w.plowTrucks = 2;
				mixedWeatherTemp(w);
				valid = true;
			}
		}
	} while (valid == false);
}

void mixedWeatherTemp(Weather& w)
{
	bool valid = false;
	cout << "Enter the temperature: ";

	do
	{
		cin >> w.temp;
		if (w.temp < -15)
		{
			if (w.precipitation <= 5.75)
			{
				w.sandTrucks = "1 light";
				w.saltTrucks = "0";
				valid = true;
			}
			else
			{
				w.sandTrucks = "1 heavy";
				w.saltTrucks = "0";
				valid = true;
			}
		}
		else if (w.temp > -7)
		{
			if (w.precipitation < 16.5)
			{
				if (w.precipitation <= 5.75)
				{
					cout << "No action needed" << endl;
					w.plowTrucks = 0;
					w.saltTrucks = "0";
					w.sandTrucks = "0";
					valid = true;
				}
				else
				{
					w.saltTrucks = "1 normal";
					w.sandTrucks = "0";
					valid = true;
				}
			}
			else
			{
				w.saltTrucks = "1 light";
				w.sandTrucks = "0";
				valid = true;
			}
		}
		else 
		{
			if (w.precipitation <= 5.75)
			{
				w.saltTrucks = "1 light";
				w.sandTrucks = "0";
				valid = true;
			}
			else
			{
				w.saltTrucks = "1 heavy";
				w.sandTrucks = "0";
				valid = true;
			}
		}
	} while (valid == false);
}

void promptUser(char command, Weather& w)
{
	switch (command)
	{
	case 'S':
	case 's':
		w.weatherType = "Snow";
		w.preUnit = "cm";
		snowWeather(w);
		w.exitFlag = 1;
		break;
	case 'I':
	case 'i':
		w.weatherType = "Ice";
		w.preUnit = "mm";
		iceWeather(w);
		w.exitFlag = 1;
		break;
	case 'M':
	case 'm':
		w.weatherType = "Mixed";
		w.preUnit = "cm";
		mixedWeather(w);
		w.exitFlag = 1;
		break;
	case 'Y':
	case 'y':
		w.exitFlag = 1;
		break;
	default:
		cout << "Please re-enter your choice!!" << endl;
		break;
	}
}

int main()
{
	Weather w;
	char prompt = 'N';
	w.exitFlag = 0;
	do
	{
		cout << "M/m = Mixed, S/s = Snow, I/i = Ice" << endl;
		cout << "Enter the weather type (Y or y to quit): ";
		cin >> prompt;
		promptUser(prompt, w);
	} while (w.exitFlag != 1);
	cout << "----------------------------------------" << endl;
	cout << "Weather type: " << w.weatherType << endl;
	cout << "Precipitation: " << w.precipitation << " " << w.preUnit << endl;
	cout << "Temperature: " << w.precipitation << "C" << endl;
	cout << "Number of plow trucks: " << w.plowTrucks << endl;
	cout << "Number of salt trucks: " << w.saltTrucks << endl;
	cout << "Number of sand trucks: " << w.sandTrucks << endl;
	cout << "----------------------------------------" << endl;
	cout << "Thank you for using the weather app. Now terminating" << endl;
	return 0;
}