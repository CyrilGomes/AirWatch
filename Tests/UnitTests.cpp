#include "../Model/ApplicationData.h"
#include "../Model/Date.h"
#include "../Services/ApplicationServices.h"
#include "../Services/Exceptions.h"

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
    reading1->addMeasurement(new Measurement("µg/m3", "Desc 1", 32.5), "O3");
    reading1->addMeasurement(new Measurement("µg/m3", "Desc 2", 23.1), "SO2");
    reading1->addMeasurement(new Measurement("µg/m3", "Desc 3", 83.2), "NO2");
    reading1->addMeasurement(new Measurement("µg/m3", "Desc 4", 48.7), "PM10");
    sensor1->addReading(reading1); //7

    Reading *reading2 = new Reading(tmpDate2);
    reading2->setSensor(sensor1);
    reading2->addMeasurement(new Measurement("µg/m3", "Desc 1", 30.9), "O3");
    reading2->addMeasurement(new Measurement("µg/m3", "Desc 2", 20.5), "SO2");
    reading2->addMeasurement(new Measurement("µg/m3", "Desc 3", 79.5), "NO2");
    reading2->addMeasurement(new Measurement("µg/m3", "Desc 4", 39.9), "PM10");
    sensor1->addReading(reading2); //6

    Reading *reading3 = new Reading(tmpDate3);
    reading3->setSensor(sensor1);
    reading3->addMeasurement(new Measurement("µg/m3", "Desc 1", 31.6), "O3");
    reading3->addMeasurement(new Measurement("µg/m3", "Desc 2", 22.4), "SO2");
    reading3->addMeasurement(new Measurement("µg/m3", "Desc 3", 80.6), "NO2");
    reading3->addMeasurement(new Measurement("µg/m3", "Desc 4", 40.3), "PM10");
    sensor1->addReading(reading3); //6

    Reading *reading4 = new Reading(tmpDate4);
    reading4->setSensor(sensor1);
    reading4->addMeasurement(new Measurement("µg/m3", "Desc 1", 34.5), "O3");
    reading4->addMeasurement(new Measurement("µg/m3", "Desc 2", 22.5), "SO2");
    reading4->addMeasurement(new Measurement("µg/m3", "Desc 3", 84.5), "NO2");
    reading4->addMeasurement(new Measurement("µg/m3", "Desc 4", 54.5), "PM10");
    sensor1->addReading(reading4); //8

    appData->addSensor(sensor1);
    // ---

    // Save those readings for later testing
    Reading* savedReading1 = reading1;
    Reading* savedReading2 = reading2;
    Reading* savedReading3 = reading3;
    Reading* savedReading4 = reading4;

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
    cout << endl;
    
    /* DISTANCE TESTS */
    
    /* ------------------------------- */
    // Inputs
    float iDist1 = 2; float iDist2 = 6; float iDist3 = 4; float iDist4 = 7;
    // Actual output
    float tDist = ApplicationData::distance(iDist1, iDist2, iDist3, iDist4);
    // Expected output
    float eDist = 248831;
    // Display and checks
    cout << separator << endl;
    cout << "| TESTED FUNCTION    : " << "distance()" << endl;
    cout << "| FROM CLASS         : " << "ApplicationData" << endl;
    cout << separator << endl;
    cout << "| INPUTS             : " << iDist1 << ", " << iDist2 << ", " << iDist3 << ", " << iDist4 << endl;
    cout << "| EXPECTED OUTPUT    : " << eDist << endl;
    cout << "| ACTUAL OUTPUT      : " << tDist << endl;
    cout << separator << endl;
    if (abs(tDist - eDist) < 1)
    {
        cout << "                                       Test\t: PASSED" << endl;
        cptPassed++;
    }
    else
    {
        cout << "                                       Test\t: FAILED" << endl;
        cptFailed++;
    }
    cout << endl;
    /* ------------------------------- */

    /* ATMO TESTS */
    
    /* ------------------------------- */
    // Inputs
    // none
    // Actual Outputs
    int tAtmo1 = savedReading1->atmo();
    int tAtmo2 = savedReading2->atmo(); 
    int tAtmo3 = savedReading3->atmo(); 
    int tAtmo4 = savedReading4->atmo(); 
    // Expected Outputs
    int eAtmo1 = 7; 
    int eAtmo2 = 6; 
    int eAtmo3 = 6; 
    int eAtmo4 = 8;
    // Display and checks 
    cout << separator << endl;
    cout << "| TESTED FUNCTION    : " << "atmo()" << endl;
    cout << "| FROM CLASS         : " << "Reading" << endl;
    cout << separator << endl;
    cout << "| INPUTS             : " << "none" << endl;
    cout << "| EXPECTED OUTPUTS   : " << eAtmo1 << " | " << eAtmo2 << " | " << eAtmo3 << " | " << eAtmo4 << endl;
    cout << "| ACTUAL OUTPUTS     : " << tAtmo1 << " | " << tAtmo2 << " | " << tAtmo3 << " | " << tAtmo4 << endl;
    cout << separator << endl;
    if (tAtmo1 == eAtmo1 && tAtmo2 == eAtmo2 && tAtmo3 == eAtmo3 && tAtmo4 == eAtmo4)
    {
        cout << "                                       Test\t: PASSED" << endl;
        cptPassed++;
    }
    else
    {
        cout << "                                       Test\t: FAILED" << endl;
        cptFailed++;
    }
    cout << endl;
    /* ------------------------------- */

    /* SENSOR SIMILARITY TESTS */
    
    /* ------------------------------- */
    // Inputs 
    int iSensorSimilarities11 = 2;
    Date iSensorSimilarities12 = tmpDate1;
    Date iSensorSimilarities13 = tmpDate2;
    // Actual Output
    vector<Sensor*> tSensorSimilarities1 = ApplicationServices::compareSensorSimilarities(
        iSensorSimilarities11, 
        iSensorSimilarities12, 
        iSensorSimilarities13
    ); 
    // Expected Ouput
    int eSensorSimilarities1Size = 1; int eSensorSimilarities1ID = 3;
    // Display and checks
    cout << separator << endl;
    cout << "| TESTED FUNCTION    : " << "compareSensorSimilarities()" << endl;
    cout << "| FROM CLASS         : " << "ApplicationServices" << endl;
    cout << separator << endl;
    cout << "| INPUTS             : " << iSensorSimilarities11 << ", " << iSensorSimilarities12 << ", " << iSensorSimilarities13 << endl;
    cout << "| EXPECTED OUTPUT    : " << eSensorSimilarities1ID << endl;
    cout << "| ACTUAL OUTPUT      : " << (tSensorSimilarities1.size() > 0 ? to_string(tSensorSimilarities1.at(0)->getId()) : "none") << endl;
    cout << separator << endl;
    if (tSensorSimilarities1.size() == eSensorSimilarities1Size && tSensorSimilarities1.at(0)->getId() == eSensorSimilarities1ID)
    {
        cout << "                                       Test\t: PASSED" << endl;
        cptPassed++;
    }
    else
    {
        cout << "                                       Test\t: FAILED" << endl;
        cptFailed++;
    }
    cout << endl;
    /* ------------------------------- */
    
    /* ------------------------------- */
    // Inputs 
    int iSensorSimilarities21 = 2;
    Date iSensorSimilarities22 = tmpDate3;
    Date iSensorSimilarities23 = tmpDate4;
    // Actual Output
    vector<Sensor*> tSensorSimilarities2 = ApplicationServices::compareSensorSimilarities(
        iSensorSimilarities21, 
        iSensorSimilarities22, 
        iSensorSimilarities23
    ); 
    // Expected Output
    int eSensorSimilarities2Size = 0;
    // Display and checks 
    cout << separator << endl;
    cout << "| TESTED FUNCTION    : " << "compareSensorSimilarities()" << endl;
    cout << "| FROM CLASS         : " << "ApplicationServices" << endl;
    cout << separator << endl;
    cout << "| INPUTS             : " << iSensorSimilarities21 << ", " << iSensorSimilarities22 << ", " << iSensorSimilarities23 << endl;
    cout << "| EXPECTED OUTPUT    : " << (eSensorSimilarities2Size > 0 ? "a non-empty list" : "none") << endl;
    cout << "| ACTUAL OUTPUT      : " << (tSensorSimilarities2.size() > 0 ? to_string(tSensorSimilarities2.at(0)->getId()) : "none") << endl;
    cout << separator << endl;
    if (tSensorSimilarities2.size() == eSensorSimilarities2Size)
    {
        cout << "                                       Test\t: PASSED" << endl;
        cptPassed++;
    }
    else
    {
        cout << "                                       Test\t: FAILED" << endl;
        cptFailed++;
    }
    cout << endl;
    /* ------------------------------- */
    
    // ---
    // Inputs 
    int iSensorSimilarities31 = 99;
    Date iSensorSimilarities32 = tmpDate1;
    Date iSensorSimilarities33 = tmpDate2;
    // Actual Output
    string tSensorSimilarities3 = "none";
    try {
        ApplicationServices::compareSensorSimilarities(
            iSensorSimilarities31, 
            iSensorSimilarities32, 
            iSensorSimilarities33
        ); //Sensor does not exist
    }
    catch (UnknownSensorException &e) {
        tSensorSimilarities3 = "UnknownSensorException";
    }
    catch (EmptyReadingsException &e) {
        tSensorSimilarities3 = "EmptyReadingsException";
    }
    catch (TimeSpanOutOfBoundException &e) {
        tSensorSimilarities3 = "TimeSpanOutOfBoundException";
    }
    // Expected Output
    string eSensorSimilarities3 = "UnknownSensorException";
    // Display and checks 
    cout << separator << endl;
    cout << "| TESTED FUNCTION    : " << "compareSensorSimilarities()" << endl;
    cout << "| FROM CLASS         : " << "ApplicationServices" << endl;
    cout << separator << endl;
    cout << "| INPUTS             : " << iSensorSimilarities31 << ", " << iSensorSimilarities32 << ", " << iSensorSimilarities33 << endl;
    cout << "| EXPECTED EXCEPTION : " << eSensorSimilarities3 << endl;
    cout << "| ACTUAL EXCEPTION   : " << tSensorSimilarities3 << endl;
    cout << separator << endl;
    if (tSensorSimilarities3 == "UnknownSensorException")
    {
        cout << "                                       Test\t: PASSED" << endl;
        cptPassed++;
    }
    else
    {
        cout << "                                       Test\t: FAILED" << endl;
        cptFailed++;
    }
    cout << endl;
    /* ------------------------------- */

    /* PUNCTUAL AIR QUALITY TESTS */
    
    /* ------------------------------- */
    // Inputs
    float iPunctualAirQuality11 = 0.3;
    float iPunctualAirQuality12 = 0.4;
    Date iPunctualAirQuality13 = tmpDate1;
    Date iPunctualAirQuality14 = tmpDate4;
    // Actual Output
    float tPunctualAirQuality1 = ApplicationServices::getPunctualAirQuality(
        iPunctualAirQuality11, 
        iPunctualAirQuality12, 
        iPunctualAirQuality13, 
        iPunctualAirQuality14
    ); 
    // Expected Output
    float ePunctualAirQuality1 = 6.66575970342;
    // Display and checks 
    cout << separator << endl;
    cout << "| TESTED FUNCTION    : " << "getPunctualAirQuality()" << endl;
    cout << "| FROM CLASS         : " << "ApplicationServices" << endl;
    cout << separator << endl;
    cout << "| INPUTS             : " << iPunctualAirQuality11 << ", " << iPunctualAirQuality12 << ", " << iPunctualAirQuality13 << ", " << iPunctualAirQuality14 << endl;
    cout << "| EXPECTED OUTPUT    : " << ePunctualAirQuality1 << endl;
    cout << "| ACTUAL OUTPUT      : " << tPunctualAirQuality1 << endl;
    cout << separator << endl;
    if (abs(tPunctualAirQuality1 - ePunctualAirQuality1) < 0.1)
    {
        cout << "                                       Test\t: PASSED" << endl;
        cptPassed++;
    }
    else
    {
        cout << "                                       Test\t: FAILED" << endl;
        cptFailed++;
    }
    cout << endl;
    /* ------------------------------- */
    
    /* ------------------------------- */
    // Inputs
    float iPunctualAirQuality21 = 0.3;
    float iPunctualAirQuality22 = 0.4;
    Date iPunctualAirQuality23(12, 4, 5, 2020);
    Date iPunctualAirQuality24(12, 6, 5, 2020);
    // Actual Output
    string tPunctualAirQuality2 = "none";
    try {
        ApplicationServices::getPunctualAirQuality(
            iPunctualAirQuality21, 
            iPunctualAirQuality22, 
            iPunctualAirQuality23, 
            iPunctualAirQuality24
        ); //Wrong time span
    }
    catch (TimeSpanOutOfBoundException &e) {
        tPunctualAirQuality2 = "TimeSpanOutOfBoundException";
    }
    catch (LocationTooFarAwayException &e) {
        tPunctualAirQuality2 = "LocationTooFarAwayException";
    }
    // Expected Output
    string ePunctualAirQuality2 = "TimeSpanOutOfBoundException";
    // Display and checks 
    cout << separator << endl;
    cout << "| TESTED FUNCTION    : " << "getPunctualAirQuality() from ApplicationServices" << endl;
    cout << separator << endl;
    cout << "| INPUTS             : " << iPunctualAirQuality21 << ", " << iPunctualAirQuality22 << ", " << iPunctualAirQuality23 << ", " << iPunctualAirQuality24 << endl;
    cout << "| EXPECTED EXCEPTION : " << ePunctualAirQuality2 << endl;
    cout << "| ACTUAL EXCEPTION   : " << tPunctualAirQuality2 << endl;
    cout << separator << endl;
    if (tPunctualAirQuality2 == ePunctualAirQuality2)
    {
        cout << "                                       Test\t: PASSED" << endl;
        cptPassed++;
    }
    else
    {
        cout << "                                       Test\t: FAILED" << endl;
        cptFailed++;
    }
    cout << endl;
    /* ------------------------------- */
    
    /* ------------------------------- */
    // Inputs
    float iPunctualAirQuality31 = 48;
    float iPunctualAirQuality32 = 68;
    Date iPunctualAirQuality33 = tmpDate1;
    Date iPunctualAirQuality34 = tmpDate4;
    // Actual Output
    string tPunctualAirQuality3 = "none";
    try {
        ApplicationServices::getPunctualAirQuality(
            iPunctualAirQuality31, 
            iPunctualAirQuality32, 
            iPunctualAirQuality33, 
            iPunctualAirQuality34
        ); //Point too far away
    }
    catch (TimeSpanOutOfBoundException &e) {
        tPunctualAirQuality3 = "TimeSpanOutOfBoundException";
    }
    catch (LocationTooFarAwayException &e) {
        tPunctualAirQuality3 = "LocationTooFarAwayException";
    }
    // Expected Output
    string ePunctualAirQuality3 = "LocationTooFarAwayException";
    // Display and checks
    cout << separator << endl;
    cout << "| TESTED FUNCTION    : " << "getPunctualAirQuality()" << endl;
    cout << "| FROM CLASS         : " << "ApplicationServices" << endl;
    cout << separator << endl;
    cout << "| INPUTS             : " << iPunctualAirQuality31 << ", " << iPunctualAirQuality32 << ", " << iPunctualAirQuality33 << ", " << iPunctualAirQuality34 << endl;
    cout << "| EXPECTED EXCEPTION : " << ePunctualAirQuality3 << endl;
    cout << "| ACTUAL EXCEPTION   : " << tPunctualAirQuality3 << endl;
    cout << separator << endl;
    if (tPunctualAirQuality3 == ePunctualAirQuality3)
    {
        cout << "                                       Test\t: PASSED" << endl;
        cptPassed++;
    }
    else
    {
        cout << "                                       Test\t: FAILED" << endl;
        cptFailed++;
    }
    cout << endl;
    /* ------------------------------- */

    /* CLEANER CONTRIBUTION TESTS */
    
    /* ------------------------------- */
    // Inputs
    int iCleanerContribution = 1;
    // Actual Output
    pair<float, float> tCleanerContribution = ApplicationServices::getCleanerContribution(iCleanerContribution);
    // Expected Output
    pair<float, float> eCleanerContribution = make_pair(55667, 2);
    // Display and checks 
    cout << separator << endl;
    cout << "| TESTED FUNCTION    : " << "getCleanerContribution()" << endl;
    cout << "| FROM CLASS         : " << "ApplicationServices" << endl;
    cout << separator << endl;
    cout << "| INPUTS             : " << iCleanerContribution << endl;
    cout << "| EXPECTED OUTPUTS   : " << eCleanerContribution.first << " \t " << eCleanerContribution.second << endl;
    cout << "| ACTUAL OUTPUTS     : " << tCleanerContribution.first << " \t " << tCleanerContribution.second << endl;
    cout << separator << endl;
    if (abs(tCleanerContribution.first - eCleanerContribution.first) < 1 && (abs(tCleanerContribution.second - eCleanerContribution.second) < 0.1))
    {
        cout << "                                       Test\t: PASSED" << endl;
        cptPassed++;
    }
    else
    {
        cout << "                                       Test\t: FAILED" << endl;
        cptFailed++;
    }
    cout << endl;
    /* ------------------------------- */

    /* ALL TESTS */
    cout << "Passed tests     : " << cptPassed << endl;
    cout << "Failed tests     : " << cptFailed << endl;
    cout << "-----------------------" << endl;
    cout << "Total            : " << cptPassed + cptFailed << endl;
    
    delete appData;

    return 0;
}