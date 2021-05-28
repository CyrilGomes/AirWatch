#include "../Model/ApplicationData.h"
#include "../Services/ApplicationServices.h"
#include "../Model/Date.h"
#include <iostream>
#include "assert.h"
using namespace std;

int main()
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
    Sensor *sensor1 = new Sensor(1, 0.0, 0.0);
    
    Reading *reading1 = new Reading(tmpDate1);
    reading1->setSensor(sensor1);
    reading1->addMeasurement(new Measurement("µg/m3", "Desc 1", 34.5), "O3");
    reading1->addMeasurement(new Measurement("µg/m3", "Desc 2", 22.5), "SO2");
    reading1->addMeasurement(new Measurement("µg/m3", "Desc 3", 84.5), "NO2");
    reading1->addMeasurement(new Measurement("µg/m3", "Desc 4", 54.5), "PM10");
    sensor1->addReading(reading1); //8

    Reading *reading2 = new Reading(tmpDate2);
    reading2->setSensor(sensor1);
    reading2->addMeasurement(new Measurement("µg/m3", "Desc 1", 32.5), "O3");
    reading2->addMeasurement(new Measurement("µg/m3", "Desc 2", 23.1), "SO2");
    reading2->addMeasurement(new Measurement("µg/m3", "Desc 3", 83.2), "NO2");
    reading2->addMeasurement(new Measurement("µg/m3", "Desc 4", 48.7), "PM10");
    sensor1->addReading(reading2); //7

    Reading *reading3 = new Reading(tmpDate3);
    reading3->setSensor(sensor1);
    reading3->addMeasurement(new Measurement("µg/m3", "Desc 1", 31.6), "O3");
    reading3->addMeasurement(new Measurement("µg/m3", "Desc 2", 22.4), "SO2");
    reading3->addMeasurement(new Measurement("µg/m3", "Desc 3", 80.6), "NO2");
    reading3->addMeasurement(new Measurement("µg/m3", "Desc 4", 40.3), "PM10");
    sensor1->addReading(reading3); //6

    Reading *reading4 = new Reading(tmpDate4);
    reading4->setSensor(sensor1);
    reading4->addMeasurement(new Measurement("µg/m3", "Desc 1", 30.9), "O3");
    reading4->addMeasurement(new Measurement("µg/m3", "Desc 2", 20.5), "SO2");
    reading4->addMeasurement(new Measurement("µg/m3", "Desc 3", 79.5), "NO2");
    reading4->addMeasurement(new Measurement("µg/m3", "Desc 4", 39.9), "PM10");
    sensor1->addReading(reading4); //6
    
    appData->addSensor(sensor1);
    // ---
    
    // Compute and save atmo values for later testing
    int tAtmo1 = reading1->atmo(); //8
    int tAtmo2 = reading2->atmo(); //7
    int tAtmo3 = reading3->atmo(); //6
    int tAtmo4 = reading4->atmo(); //6

    // SENSOR 2
    Sensor *sensor2 = new Sensor(2, 1.0, 0.0);
    
    reading1 = new Reading(tmpDate1);
    reading1->setSensor(sensor2);
    reading1->addMeasurement(new Measurement("µg/m3", "Desc 1", 105.5), "O3");
    reading1->addMeasurement(new Measurement("µg/m3", "Desc 2", 120.5), "SO2");
    reading1->addMeasurement(new Measurement("µg/m3", "Desc 3", 136.4), "NO2");
    reading1->addMeasurement(new Measurement("µg/m3", "Desc 4", 25.1), "PM10");
    sensor2->addReading(reading1); //6

    reading2 = new Reading(tmpDate2);
    reading2->setSensor(sensor2);
    reading2->addMeasurement(new Measurement("µg/m3", "Desc 1", 110.2), "O3");
    reading2->addMeasurement(new Measurement("µg/m3", "Desc 2", 125.1), "SO2");
    reading2->addMeasurement(new Measurement("µg/m3", "Desc 3", 133.8), "NO2");
    reading2->addMeasurement(new Measurement("µg/m3", "Desc 4", 26.2), "PM10");
    sensor2->addReading(reading2); //5

    reading3 = new Reading(tmpDate3);
    reading3->setSensor(sensor2);
    reading3->addMeasurement(new Measurement("µg/m3", "Desc 1", 112.8), "O3");
    reading3->addMeasurement(new Measurement("µg/m3", "Desc 2", 126.6), "SO2");
    reading3->addMeasurement(new Measurement("µg/m3", "Desc 3", 137.1), "NO2");
    reading3->addMeasurement(new Measurement("µg/m3", "Desc 4", 24.5), "PM10");
    sensor2->addReading(reading3); //6

    reading4 = new Reading(tmpDate4);
    reading4->setSensor(sensor2);
    reading4->addMeasurement(new Measurement("µg/m3", "Desc 1", 123.9), "O3");
    reading4->addMeasurement(new Measurement("µg/m3", "Desc 2", 130.5), "SO2");
    reading4->addMeasurement(new Measurement("µg/m3", "Desc 3", 165.8), "NO2");
    reading4->addMeasurement(new Measurement("µg/m3", "Desc 4", 25.7), "PM10");
    sensor2->addReading(reading4); //7
    
    appData->addSensor(sensor2);
    // ---

    // SENSOR 3
    Sensor *sensor3 = new Sensor(3, 1.0, 1.0);
    
    reading1 = new Reading(tmpDate1);
    reading1->setSensor(sensor3);
    reading1->addMeasurement(new Measurement("µg/m3", "Desc 1", 106.6), "O3");
    reading1->addMeasurement(new Measurement("µg/m3", "Desc 2", 120.7), "SO2");
    reading1->addMeasurement(new Measurement("µg/m3", "Desc 3", 138.2), "NO2");
    reading1->addMeasurement(new Measurement("µg/m3", "Desc 4", 26.4), "PM10");
    sensor3->addReading(reading1); //6

    reading2 = new Reading(tmpDate2);
    reading2->setSensor(sensor3);
    reading2->addMeasurement(new Measurement("µg/m3", "Desc 1", 108.1), "O3");
    reading2->addMeasurement(new Measurement("µg/m3", "Desc 2", 130.5), "SO2");
    reading2->addMeasurement(new Measurement("µg/m3", "Desc 3", 124.8), "NO2");
    reading2->addMeasurement(new Measurement("µg/m3", "Desc 4", 21.7), "PM10");
    sensor3->addReading(reading2); //5

    reading3 = new Reading(tmpDate3);
    reading3->setSensor(sensor3);
    reading3->addMeasurement(new Measurement("µg/m3", "Desc 1", 225.8), "O3");
    reading3->addMeasurement(new Measurement("µg/m3", "Desc 2", 221.2), "SO2");
    reading3->addMeasurement(new Measurement("µg/m3", "Desc 3", 242.6), "NO2");
    reading3->addMeasurement(new Measurement("µg/m3", "Desc 4", 43.2), "PM10");
    sensor3->addReading(reading3); //9

    reading4 = new Reading(tmpDate4);
    reading4->setSensor(sensor3);
    reading4->addMeasurement(new Measurement("µg/m3", "Desc 1", 228.2), "O3");
    reading4->addMeasurement(new Measurement("µg/m3", "Desc 2", 241.8), "SO2");
    reading4->addMeasurement(new Measurement("µg/m3", "Desc 3", 272.2), "NO2");
    reading4->addMeasurement(new Measurement("µg/m3", "Desc 4", 46.1), "PM10");
    sensor3->addReading(reading4); //9
    
    appData->addSensor(sensor3);
    // ---

    // CLEANERS
    appData->addCleaner(new Cleaner(1, 0, -0.5, tmpDate1, tmpDate3));
    appData->addCleaner(new Cleaner(2, 0, 1.5, tmpDate2, tmpDate3));
    // ---

    /* --------------------------------------------------------------------- */
    /* ------------------------------- TESTS --------------------------------*/
    /* --------------------------------------------------------------------- */

    int cptPassed = 0;
    int cptFailed = 0;
    string separator = "-----------------------------------------------------------";

    /* DISTANCE TESTS */
    float tDist = ApplicationData::distance(2, 6, 4, 7);
    cout << separator << endl;
    cout << "| TESTED FUNCTION : " << "distance() from ApplicationData" << endl;
    cout << separator << endl;
    cout << "| INPUTS          : " << "2, 6, 4, 7" << endl;
    cout << "| EXPECTED OUTPUT : " << "248831" << endl;
    cout << "| ACTUAL OUTPUT   : " << tDist << endl;
    cout << separator << endl;
    if (abs(tDist - 248831) < 1) {
        cout << "                                       Test\t: PASSED" << endl;
        cptPassed++;
    }
    else {
        cout << "                                       Test\t: FAILED" << endl;
        cptFailed++;
    }
    cout << endl;
    /* ------------------------------- */

    /* ATMO TESTS */
    // atmo values computed after defining sensor 1
    cout << separator << endl;
    cout << "| TESTED FUNCTION : " << "atmo() from Reading" << endl;
    cout << separator << endl;
    cout << "| INPUTS          : " << "none" << endl;
    cout << "| EXPECTED OUTPUT : " << "8 \t 7 \t 6 \t 6" << endl;
    cout << "| ACTUAL OUTPUT   : " << tAtmo1 << " \t " << tAtmo2 << " \t " << tAtmo3 << " \t " << tAtmo4 << endl;
    cout << separator << endl;
    if (tAtmo1 == 8 && tAtmo2 == 7 && tAtmo3 == 6 && tAtmo4 == 6) {
        cout << "                                       Test\t: PASSED" << endl;
        cptPassed++;
    }
    else {
        cout << "                                       Test\t: FAILED" << endl;
        cptFailed++;
    }
    cout << endl;
    /* ------------------------------- */

    /* SENSOR SIMILARITY TESTS */
    vector<Sensor*> tSensorSimilarities1 = ApplicationServices::compareSensorSimilarities(2, tmpDate1, tmpDate2); //similar sensor: 3
    vector<Sensor*> tSensorSimilarities2 = ApplicationServices::compareSensorSimilarities(2, tmpDate3, tmpDate4); //no similar sensors
    cout << separator << endl;
    cout << "| TESTED FUNCTION : " << "compareSensorSimilarities() from ApplicationServices" << endl;
    cout << separator << endl;
    cout << "| INPUTS          : " << "2, 27/05/2021, 28/05/2021" << endl;
    cout << "| EXPECTED OUTPUT : " << "3" << endl;
    cout << "| ACTUAL OUTPUT   : " << (tSensorSimilarities1.size() > 0 ? to_string(tSensorSimilarities1.at(0)->getId()) : "none") << endl;
    cout << separator << endl;
    if (tSensorSimilarities1.size() == 1 && tSensorSimilarities1.at(0)->getId() == 3) {
        cout << "                                       Test\t: PASSED" << endl;
        cptPassed++;
    }
    else {
        cout << "                                       Test\t: FAILED" << endl;
        cptFailed++;
    }
    cout << endl;
    cout << separator << endl;
    cout << "| TESTED FUNCTION : " << "compareSensorSimilarities() from ApplicationServices" << endl;
    cout << separator << endl;
    cout << "| INPUTS          : " << "2, 29/05/2021, 30/05/2021" << endl;
    cout << "| EXPECTED OUTPUT : " << "none" << endl;
    cout << "| ACTUAL OUTPUT   : " << (tSensorSimilarities2.size() > 0 ? to_string(tSensorSimilarities2.at(0)->getId()) : "none") << endl;
    cout << separator << endl;
    if (tSensorSimilarities2.size() == 0) {
        cout << "                                       Test\t: PASSED" << endl;
        cptPassed++;
    }
    else {
        cout << "                                       Test\t: FAILED" << endl;
        cptFailed++;
    }
    cout << endl;
    /* ------------------------------- */

    /* PUNCTUAL AIR QUALITY TESTS */
    float tPunctualAirQuality = ApplicationServices::getPunctualAirQuality(0.3, 0.4, tmpDate1, tmpDate4); //6.66575970342
    cout << separator << endl;
    cout << "| TESTED FUNCTION : " << "getPunctualAirQuality() from ApplicationServices" << endl;
    cout << separator << endl;
    cout << "| INPUTS          : " << "0.3, 0.4, 27/05/2021, 30/05/2021" << endl;
    cout << "| EXPECTED OUTPUT : " << "6.66575970342" << endl;
    cout << "| ACTUAL OUTPUT   : " << tPunctualAirQuality << endl;
    cout << separator << endl;
    if (abs(tPunctualAirQuality - 6.66575970342) < 0.1) {
        cout << "                                       Test\t: PASSED" << endl;
        cptPassed++;
    }
    else {
        cout << "                                       Test\t: FAILED" << endl;
        cptFailed++;
    }
    cout << endl;
    /* ------------------------------- */

    /* CLEANER CONTRIBUTION TESTS */
    pair<float,float> tCleanerContribution = ApplicationServices::getCleanerContribution(1);
    cout << separator << endl;
    cout << "| TESTED FUNCTION : " << "getCleanerContribution() from ApplicationServices" << endl;
    cout << separator << endl;
    cout << "| INPUTS          : " << "1" << endl;
    cout << "| EXPECTED OUTPUT : " << "55667 \t 2" << endl;
    cout << "| ACTUAL OUTPUT   : " << tCleanerContribution.first << " \t " << tCleanerContribution.second << endl;
    cout << separator << endl;
    if(abs(tCleanerContribution.first - 55667) < 1 && (abs(tCleanerContribution.second - 2) < 0.1)) {
        cout << "                                       Test\t: PASSED" << endl;
        cptPassed++;
    }
    else {
        cout << "                                       Test\t: FAILED" << endl;
        cptFailed++;
    }
    /* ------------------------------- */
    
    cout << "Passed tests     : " << cptPassed << endl;
    cout << "Failed tests     : " << cptFailed << endl;
    cout << "-----------------------" << endl;
    cout << "Total            : " << cptPassed + cptFailed << endl;

    return 0;
}