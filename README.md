# AirWatch

To execute the program, compile it using `make`. Then launch it using the generated .exe file (`./AirWatch.exe`).
In order to see the execution times of each algorithm, compile using `make debug` to add the DEBUG flag.

Execute tests by going in the Tests/ directory and compiling the tests using `make`. 
You can then execute unit tests by launching `./UnitTests.exe`, and integration tests by launching `./IntegrationTests.exe`. 

**Note:** the program has to be compiled without the DEBUG flag, otherwise the tests won't work. If the application has already been compiled with the DEBUG flag, execute `make clean` and compile again without the DEBUG flag.

For more information on how to use the program, please look at the User Manual in the Requirements Specifications .pdf from the doc/ folder

The only features not implemented in this build are the getAreaAirQuality(), checkSensorsReliabilities() and flagSensor() services.

Here are the available logins you can use to access and test the application:
- Government Agent: 
admin@mail.gov; password
- Air Cleaning Companies: 
company1@mail.com; abcdef
company2@mail.com; abcdef
company3@mail.com; abcdef
company3@mail.com;newPassword
- Private Individuals:
user0@mail.com; 123456
user1@mail.com; 123456
user2@mail.com; 123456
user3@mail.com; 123456
user4@mail.com; 123456
