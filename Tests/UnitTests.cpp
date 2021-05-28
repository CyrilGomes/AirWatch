#include "../Model/ApplicationData.h"
#include "../Services/ApplicationServices.h"
#include "../Model/Date.h"
#include <iostream>
#include "assert.h"
using namespace std;

void doUnitTests()
{
    
    /* --------------------------------------------------------------------- */
    /* ------------------------------- DATA ---------------------------------*/
    /* --------------------------------------------------------------------- */
    
    // Get Data
    ApplicationData *appData = ApplicationData::getInstance();
    
    // DATES
    Date tmpDate1(12, 27, 5, 2021);
    Date tmpDate2(12, 28, 5, 2021);
    Date tmpDate3(12, 29, 5, 2021);
    Date tmpDate4(12, 30, 5, 2021);
    // ---

    // SENSOR 1
    Sensor *sensor1 = new Sensor(1, 1.9, 1.8);
    
    Reading *reading1 = new Reading(tmpDate1);
    reading1->setSensor(sensor1);
    reading1->addMeasurement(new Measurement("µg/m3", "Desc 1", 34.5), "O3");
    reading1->addMeasurement(new Measurement("µg/m3", "Desc 2", 22.5), "SO2");
    reading1->addMeasurement(new Measurement("µg/m3", "Desc 3", 84.5), "NO2");
    reading1->addMeasurement(new Measurement("µg/m3", "Desc 4", 54.5), "PM10");
    sensor1->addReading(reading1);

    Reading *reading2 = new Reading(tmpDate2);
    reading2->setSensor(sensor1);
    reading2->addMeasurement(new Measurement("µg/m3", "Desc 1", 32.5), "O3");
    reading2->addMeasurement(new Measurement("µg/m3", "Desc 2", 48.5), "SO2");
    reading2->addMeasurement(new Measurement("µg/m3", "Desc 3", 20.5), "NO2");
    reading2->addMeasurement(new Measurement("µg/m3", "Desc 4", 14.5), "PM10");
    sensor1->addReading(reading2);

    Reading *reading3 = new Reading(tmpDate3);
    reading3->setSensor(sensor1);
    reading3->addMeasurement(new Measurement("µg/m3", "Desc 1", 11.5), "O3");
    reading3->addMeasurement(new Measurement("µg/m3", "Desc 2", 48.5), "SO2");
    reading3->addMeasurement(new Measurement("µg/m3", "Desc 3", 2.5), "NO2");
    reading3->addMeasurement(new Measurement("µg/m3", "Desc 4", 26.5), "PM10");
    sensor1->addReading(reading3);

    Reading *reading4 = new Reading(tmpDate4);
    reading4->setSensor(sensor1);
    reading4->addMeasurement(new Measurement("µg/m3", "Desc 1", 26.5), "O3");
    reading4->addMeasurement(new Measurement("µg/m3", "Desc 2", 12.5), "SO2");
    reading4->addMeasurement(new Measurement("µg/m3", "Desc 3", 48.5), "NO2");
    reading4->addMeasurement(new Measurement("µg/m3", "Desc 4", 68.5), "PM10");
    sensor1->addReading(reading4);
    
    appData->addSensor(sensor1);
    // ---
    
    // Compute and save atmo values for later testing
    int atmoTest1 = reading1->atmo(); //8
    int atmoTest2 = reading2->atmo(); //3
    int atmoTest3 = reading3->atmo(); //4
    int atmoTest4 = reading4->atmo(); //9

    // SENSOR 2
    Sensor *sensor2 = new Sensor(2, 2.1, 2.1);
    
    reading1 = new Reading(tmpDate1);
    reading1->setSensor(sensor2);
    reading1->addMeasurement(new Measurement("µg/m3", "Desc 1", 19.5), "O3");
    reading1->addMeasurement(new Measurement("µg/m3", "Desc 2", 20.5), "SO2");
    reading1->addMeasurement(new Measurement("µg/m3", "Desc 3", 17.5), "NO2");
    reading1->addMeasurement(new Measurement("µg/m3", "Desc 4", 46.5), "PM10");
    sensor2->addReading(reading1);

    reading2 = new Reading(tmpDate2);
    reading2->setSensor(sensor2);
    reading2->addMeasurement(new Measurement("µg/m3", "Desc 1", 85.5), "O3");
    reading2->addMeasurement(new Measurement("µg/m3", "Desc 2", 16.5), "SO2");
    reading2->addMeasurement(new Measurement("µg/m3", "Desc 3", 34.5), "NO2");
    reading2->addMeasurement(new Measurement("µg/m3", "Desc 4", 7.5), "PM10");
    sensor2->addReading(reading2);

    reading3 = new Reading(tmpDate3);
    reading3->setSensor(sensor2);
    reading3->addMeasurement(new Measurement("µg/m3", "Desc 1", 59.5), "O3");
    reading3->addMeasurement(new Measurement("µg/m3", "Desc 2", 40.5), "SO2");
    reading3->addMeasurement(new Measurement("µg/m3", "Desc 3", 20.5), "NO2");
    reading3->addMeasurement(new Measurement("µg/m3", "Desc 4", 14.5), "PM10");
    sensor2->addReading(reading3);

    reading4 = new Reading(tmpDate4);
    reading4->setSensor(sensor2);
    reading4->addMeasurement(new Measurement("µg/m3", "Desc 1", 26.5), "O3");
    reading4->addMeasurement(new Measurement("µg/m3", "Desc 2", 12.2), "SO2");
    reading4->addMeasurement(new Measurement("µg/m3", "Desc 3", 48.5), "NO2");
    reading4->addMeasurement(new Measurement("µg/m3", "Desc 4", 68.1), "PM10");
    sensor2->addReading(reading4);
    
    appData->addSensor(sensor2);
    // ---

    // SENSOR 3
    Sensor *sensor3 = new Sensor(3, 2.04, 3.05);
    
    reading1 = new Reading(tmpDate1);
    reading1->setSensor(sensor3);
    reading1->addMeasurement(new Measurement("µg/m3", "Desc 1", 34.8), "O3");
    reading1->addMeasurement(new Measurement("µg/m3", "Desc 2", 22.3), "SO2");
    reading1->addMeasurement(new Measurement("µg/m3", "Desc 3", 84.4), "NO2");
    reading1->addMeasurement(new Measurement("µg/m3", "Desc 4", 54.6), "PM10");
    sensor3->addReading(reading1);

    reading2 = new Reading(tmpDate2);
    reading2->setSensor(sensor3);
    reading2->addMeasurement(new Measurement("µg/m3", "Desc 1", 32.5), "O3");
    reading2->addMeasurement(new Measurement("µg/m3", "Desc 2", 48.5), "SO2");
    reading2->addMeasurement(new Measurement("µg/m3", "Desc 3", 20.5), "NO2");
    reading2->addMeasurement(new Measurement("µg/m3", "Desc 4", 14.5), "PM10");
    sensor3->addReading(reading2);

    reading3 = new Reading(tmpDate3);
    reading3->setSensor(sensor3);
    reading3->addMeasurement(new Measurement("µg/m3", "Desc 1", 11.5), "O3");
    reading3->addMeasurement(new Measurement("µg/m3", "Desc 2", 48.4), "SO2");
    reading3->addMeasurement(new Measurement("µg/m3", "Desc 3", 2.6), "NO2");
    reading3->addMeasurement(new Measurement("µg/m3", "Desc 4", 26.3), "PM10");
    sensor3->addReading(reading3);

    reading4 = new Reading(tmpDate4);
    reading4->setSensor(sensor3);
    reading4->addMeasurement(new Measurement("µg/m3", "Desc 1", 26.5), "O3");
    reading4->addMeasurement(new Measurement("µg/m3", "Desc 2", 12.2), "SO2");
    reading4->addMeasurement(new Measurement("µg/m3", "Desc 3", 48.5), "NO2");
    reading4->addMeasurement(new Measurement("µg/m3", "Desc 4", 68.1), "PM10");
    sensor3->addReading(reading4);
    
    appData->addSensor(sensor3);
    // ---

    // CLEANERS
    appData->addCleaner(new Cleaner(1, 2, 2.2, tmpDate2, tmpDate3));
    appData->addCleaner(new Cleaner(2, 54, 48, tmpDate2, tmpDate3));
    appData->addCleaner(new Cleaner(3, 68, 21, tmpDate2, tmpDate3));
    appData->addCleaner(new Cleaner(4, 16, 3, tmpDate2, tmpDate3));
    // ---

    /* --------------------------------------------------------------------- */
    /* ------------------------------- TESTS --------------------------------*/
    /* --------------------------------------------------------------------- */

    /* DISTANCE TESTS */
    if (abs(ApplicationData::distance(2, 6, 4, 7) - 248831) < 1)
    {
        cout << "Distance test : Success !" << endl;
    }
    else
    {
        cout << "Distance test : Fail !" << endl;
    }
    /* ------------------------------- */

    /* ATMO TESTS */
    // atmo values computed after defining sensor 1
    if (atmoTest1 == 8 && atmoTest2 == 3 && atmoTest3 == 4 && atmoTest4 == 9) 
    {
        cout << "Atmo test: Success !" << endl;
    }
    else
    {
        cout << "Atmo test: Fail !" << endl;
    }
    /* ------------------------------- */

    /* SENSOR SIMILARITY TESTS */
    vector<Sensor *> resultSensorSimilaritiesLimitedSpanTest = ApplicationServices::compareSensorSimilarities(1, tmpDate4, tmpDate4);
    vector<Sensor *> resultSensorSimilaritiesFullSpanTest = ApplicationServices::compareSensorSimilarities(1, tmpDate1, tmpDate4);
    if (resultSensorSimilaritiesFullSpanTest.size() == 1
    && resultSensorSimilaritiesFullSpanTest.at(0)->getId() == 3) 
    {
        cout << "Compare Sensor Similarities test (Full Time Span): Success !" << endl;
    }
    else
    {
        cout << "Compare Sensor Similarities test (Full Time Span): Fail !" << endl;
    }
    if (resultSensorSimilaritiesLimitedSpanTest.size() == 2 
    && resultSensorSimilaritiesLimitedSpanTest.at(0)->getId() == 3 
    && resultSensorSimilaritiesLimitedSpanTest.at(1)->getId() == 2) 
    {
        cout << "Compare Sensor Similarities test 2 (Limited Time Span): Success !" << endl;
    }
    else
    {
        cout << "Compare Sensor Similarities test 2 (Limited Time Span): Fail !" << endl;
    }
    /* ------------------------------- */

    /* PUNCTUAL AIR QUALITY TESTS */
    float resultPunctualAirQualityTest = ApplicationServices::getPunctualAirQuality(2, 2, tmpDate1, tmpDate4);
    if (abs(resultPunctualAirQualityTest - 5.822) < 0.1) //Air Quality Test
    {
        cout << "Punctual Air Quality test: Success !" << endl;
    }
    else
    {
        cout << "Punctual Air Quality test: Fail !" << endl;
    }
    /* ------------------------------- */

    /* CLEANER CONTRIBUTION TESTS */
    pair<float,float> resultCleanerContributionTest = ApplicationServices::getCleanerContribution(1);
    if(abs(resultCleanerContributionTest.first - 94668.1) < 1 && (abs(resultCleanerContributionTest.second - 5.66)<0.1))
    {
        cout << "Cleaner Contribution test: Success !" << endl;
    }
    else
    {
        cout << "Cleaner Contribution test: Fail !" << endl;
    }
    /* ------------------------------- */

}

int main() {
    doUnitTests();
    return 0;
}