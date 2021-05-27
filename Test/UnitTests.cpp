#include "../Model/ApplicationData.h"
#include "../Services/ApplicationServices.h"
#include "../Model/Date.h"
#include <iostream>
#include "assert.h"
using namespace std;

void doUnitTests()
{

    if (abs(ApplicationData::distance(2, 6, 4, 7) - 248831) < 1)
    {
        cout << "Distance test : Success !" << endl;
    }
    else
    {
        cout << "Distance test : Fail !" << endl;
    }

    ApplicationData *appData = ApplicationData::getInstance();
    Sensor *sensor1 = new Sensor(1, 1.9, 1.8);

    Date tmpDate1(12, 27, 5, 2021);
    Date tmpDate2(12, 28, 5, 2021);
    Date tmpDate3(12, 29, 5, 2021);
    Date tmpDate4(12, 30, 5, 2021);

    int atmoTest1 = 0;
    int atmoTest2 = 0;
    int atmoTest3 = 0;
    int atmoTest4 = 0;

    //Debut Sensor 1
    Reading *reading1 = new Reading(tmpDate1);
    reading1->setSensor(sensor1);
    Measurement *measurement1 = new Measurement("µg/m3", "Desc 1", 34.5);
    reading1->addMeasurement(measurement1, "O3");
    Measurement *measurement2 = new Measurement("µg/m3", "Desc 2", 22.5);
    reading1->addMeasurement(measurement2, "SO2");
    Measurement *measurement3 = new Measurement("µg/m3", "Desc 3", 84.5);
    reading1->addMeasurement(measurement3, "NO2");
    Measurement *measurement4 = new Measurement("µg/m3", "Desc 4", 54.5);
    reading1->addMeasurement(measurement4, "PM10");

    sensor1->addReading(reading1);

    Reading *reading2 = new Reading(tmpDate2);
    reading2->setSensor(sensor1);
    measurement1 = new Measurement("µg/m3", "Desc 1", 32.5);
    reading2->addMeasurement(measurement1, "O3");
    measurement2 = new Measurement("µg/m3", "Desc 2", 48.5);
    reading2->addMeasurement(measurement2, "SO2");
    measurement3 = new Measurement("µg/m3", "Desc 3", 20.5);
    reading2->addMeasurement(measurement3, "NO2");
    measurement4 = new Measurement("µg/m3", "Desc 4", 14.5);
    reading2->addMeasurement(measurement4, "PM10");
    sensor1->addReading(reading2);

    Reading *reading3 = new Reading(tmpDate3);
    reading3->setSensor(sensor1);
    measurement1 = new Measurement("µg/m3", "Desc 1", 11.5);
    reading3->addMeasurement(measurement1, "O3");
    measurement2 = new Measurement("µg/m3", "Desc 2", 48.5);
    reading3->addMeasurement(measurement2, "SO2");
    measurement3 = new Measurement("µg/m3", "Desc 3", 2.5);
    reading3->addMeasurement(measurement3, "NO2");
    measurement4 = new Measurement("µg/m3", "Desc 4", 26.5);
    reading3->addMeasurement(measurement4, "PM10");
    sensor1->addReading(reading3);

    Reading *reading4 = new Reading(tmpDate4);
    reading4->setSensor(sensor1);
    measurement1 = new Measurement("µg/m3", "Desc 1", 26.5);
    reading4->addMeasurement(measurement1, "O3");
    measurement2 = new Measurement("µg/m3", "Desc 2", 12.5);
    reading4->addMeasurement(measurement2, "SO2");
    measurement3 = new Measurement("µg/m3", "Desc 3", 48.5);
    reading4->addMeasurement(measurement3, "NO2");
    measurement4 = new Measurement("µg/m3", "Desc 4", 68.5);
    reading4->addMeasurement(measurement4, "PM10");
    sensor1->addReading(reading4);

    atmoTest1 = reading1->atmo(); //8
    atmoTest2 = reading2->atmo(); //3
    atmoTest3 = reading3->atmo(); //4
    atmoTest4 = reading4->atmo(); //9

    if (atmoTest1 == 8 && atmoTest2 == 3 && atmoTest3 == 4 && atmoTest4 == 9) //Test Indice Atmo
    {
        cout << "Atmo test: Success !" << endl;
    }
    else
    {
        cout << "Atmo test: Fail !" << endl;
    }

    //Fin Sensor 1

    Sensor *sensor2 = new Sensor(2, 2.1, 2.1);
    //Debut Sensor 2
    reading1 = new Reading(tmpDate1);
    reading1->setSensor(sensor2);
    measurement1 = new Measurement("µg/m3", "Desc 1", 19.5);
    reading1->addMeasurement(measurement1, "O3");
    measurement2 = new Measurement("µg/m3", "Desc 2", 20.5);
    reading1->addMeasurement(measurement2, "SO2");
    measurement3 = new Measurement("µg/m3", "Desc 3", 17.5);
    reading1->addMeasurement(measurement3, "NO2");
    measurement4 = new Measurement("µg/m3", "Desc 4", 46.5);
    reading1->addMeasurement(measurement4, "PM10");
    sensor2->addReading(reading1);

    reading2 = new Reading(tmpDate2);
    reading2->setSensor(sensor2);
    measurement1 = new Measurement("µg/m3", "Desc 1", 85.5);
    reading2->addMeasurement(measurement1, "O3");
    measurement2 = new Measurement("µg/m3", "Desc 2", 16.5);
    reading2->addMeasurement(measurement2, "SO2");
    measurement3 = new Measurement("µg/m3", "Desc 3", 34.5);
    reading2->addMeasurement(measurement3, "NO2");
    measurement4 = new Measurement("µg/m3", "Desc 4", 7.5);
    reading2->addMeasurement(measurement4, "PM10");
    sensor2->addReading(reading2);

    reading3 = new Reading(tmpDate3);
    reading3->setSensor(sensor2);
    measurement1 = new Measurement("µg/m3", "Desc 1", 59.5);
    reading3->addMeasurement(measurement1, "O3");
    measurement2 = new Measurement("µg/m3", "Desc 2", 40.5);
    reading3->addMeasurement(measurement2, "SO2");
    measurement3 = new Measurement("µg/m3", "Desc 3", 20.5);
    reading3->addMeasurement(measurement3, "NO2");
    measurement4 = new Measurement("µg/m3", "Desc 4", 14.5);
    reading3->addMeasurement(measurement4, "PM10");
    sensor2->addReading(reading3);

    reading4 = new Reading(tmpDate4);
    reading4->setSensor(sensor2);
    measurement1 = new Measurement("µg/m3", "Desc 1", 26.5);
    reading4->addMeasurement(measurement1, "O3");
    measurement2 = new Measurement("µg/m3", "Desc 2", 12.2);
    reading4->addMeasurement(measurement2, "SO2");
    measurement3 = new Measurement("µg/m3", "Desc 3", 48.5);
    reading4->addMeasurement(measurement3, "NO2");
    measurement4 = new Measurement("µg/m3", "Desc 4", 68.1);
    reading4->addMeasurement(measurement4, "PM10");
    sensor2->addReading(reading4);
    //Fin Sensor 2

    Sensor *sensor3 = new Sensor(3, 2.04, 3.05);
    //Debut Sensor 3
    reading1 = new Reading(tmpDate1);
    reading1->setSensor(sensor3);
    measurement1 = new Measurement("µg/m3", "Desc 1", 34.8);
    reading1->addMeasurement(measurement1, "O3");
    measurement2 = new Measurement("µg/m3", "Desc 2", 22.3);
    reading1->addMeasurement(measurement2, "SO2");
    measurement3 = new Measurement("µg/m3", "Desc 3", 84.4);
    reading1->addMeasurement(measurement3, "NO2");
    measurement4 = new Measurement("µg/m3", "Desc 4", 54.6);
    reading1->addMeasurement(measurement4, "PM10");
    sensor3->addReading(reading1);

    reading2 = new Reading(tmpDate2);
    reading2->setSensor(sensor3);
    measurement1 = new Measurement("µg/m3", "Desc 1", 32.5);
    reading2->addMeasurement(measurement1, "O3");
    measurement2 = new Measurement("µg/m3", "Desc 2", 48.5);
    reading2->addMeasurement(measurement2, "SO2");
    measurement3 = new Measurement("µg/m3", "Desc 3", 20.5);
    reading2->addMeasurement(measurement3, "NO2");
    measurement4 = new Measurement("µg/m3", "Desc 4", 14.5);
    reading2->addMeasurement(measurement4, "PM10");
    sensor3->addReading(reading2);

    reading3 = new Reading(tmpDate3);
    reading3->setSensor(sensor3);
    measurement1 = new Measurement("µg/m3", "Desc 1", 11.5);
    reading3->addMeasurement(measurement1, "O3");
    measurement2 = new Measurement("µg/m3", "Desc 2", 48.4);
    reading3->addMeasurement(measurement2, "SO2");
    measurement3 = new Measurement("µg/m3", "Desc 3", 2.6);
    reading3->addMeasurement(measurement3, "NO2");
    measurement4 = new Measurement("µg/m3", "Desc 4", 26.3);
    reading3->addMeasurement(measurement4, "PM10");
    sensor3->addReading(reading3);

    reading4 = new Reading(tmpDate4);
    reading4->setSensor(sensor3);
    measurement1 = new Measurement("µg/m3", "Desc 1", 26.5);
    reading4->addMeasurement(measurement1, "O3");
    measurement2 = new Measurement("µg/m3", "Desc 2", 12.2);
    reading4->addMeasurement(measurement2, "SO2");
    measurement3 = new Measurement("µg/m3", "Desc 3", 48.5);
    reading4->addMeasurement(measurement3, "NO2");
    measurement4 = new Measurement("µg/m3", "Desc 4", 68.1);
    reading4->addMeasurement(measurement4, "PM10");
    sensor3->addReading(reading4);
    //Fin Sensor 3

    appData->addSensor(sensor1);
    appData->addSensor(sensor2);
    appData->addSensor(sensor3);


    appData->addCleaner(new Cleaner(1,2,2.2,tmpDate2,tmpDate3));
    appData->addCleaner(new Cleaner(2,54,48,tmpDate2,tmpDate3));
    appData->addCleaner(new Cleaner(3,68,21,tmpDate2,tmpDate3));
    appData->addCleaner(new Cleaner(4,16,3,tmpDate2,tmpDate3));


    vector<Sensor *> resultSensorSimilaritiesLimitedSpanTest = ApplicationServices::compareSensorSimilarities(1, tmpDate4, tmpDate4);
    vector<Sensor *> resultSensorSimilaritiesFullSpanTest = ApplicationServices::compareSensorSimilarities(1, tmpDate1, tmpDate4);
    
    if (resultSensorSimilaritiesFullSpanTest.size() == 1 && resultSensorSimilaritiesFullSpanTest.at(0)->getId() == 3) //Only the Sensor3 should be similar
    {
        cout << "Compare Sensor Similarities test (Full Time Span): Success !" << endl;
    }
    else
    {
        cout << "Compare Sensor Similarities test (Full Time Span): Fail !" << endl;
    }
    if (resultSensorSimilaritiesLimitedSpanTest.size() == 2 && resultSensorSimilaritiesLimitedSpanTest.at(0)->getId() == 3 && resultSensorSimilaritiesLimitedSpanTest.at(1)->getId() == 2) //Only the Sensor3 should be similar
    {
        cout << "Compare Sensor Similarities test 2 (Limited Time Span): Success !" << endl;
    }
    else
    {
        cout << "Compare Sensor Similarities test 2 (Limited Time Span): Fail !" << endl;
    }


    float resultPunctualAirQualityTest = ApplicationServices::getPunctualAirQuality(2, 2, tmpDate1, tmpDate4);

    if (abs(resultPunctualAirQualityTest - 5.822) < 0.1) //Air Quality Test
    {
        cout << "Punctual Air Quality test: Success !" << endl;
    }
    else
    {
        cout << "Punctual Air Quality test: Fail !" << endl;
    }

    pair<float,float> resultCleanerContributionTest = ApplicationServices::getCleanerContribution(1);
    if(abs(resultCleanerContributionTest.first - 94668.1) < 1 && (abs(resultCleanerContributionTest.second - 5.66)<0.1))
    {
        cout << "Cleaner Contribution test: Success !" << endl;
    }
    else
    {
        cout << "Cleaner Contribution test: Fail !" << endl;
    }

}

int main() {
    doUnitTests();
    return 0;
}