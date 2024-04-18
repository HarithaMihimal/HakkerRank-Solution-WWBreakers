#include <iostream>
#include <cstring> // For strcmp
// Function to convert 12-hour clock time to 24-hour clock time

std::string convertTo24HourClock(std::string time12Hour) {
    int hours, minutes, seconds;
    char meridian[3];
    // Parse the input string to extract hours, minutes, seconds, and meridian

    sscanf(time12Hour.c_str(), "%02d:%02d:%02d%s", &hours, &minutes, &seconds, meridian);
    // Convert hours to 24-hour format if necessary

    if (strcmp(meridian, "PM") == 0 && hours != 12) {
        hours += 12;
    }
    else if (strcmp(meridian, "AM") == 0 && hours == 12) {
        hours = 0;
    }
    // Format the time in 24-hour format

    char time24Hour[9];
    sprintf(time24Hour, "%02d:%02d:%02d", hours, minutes, seconds);

    return time24Hour;
}

int main() {
    std::string time12Hour;
    std::cin >> time12Hour;
    // Convert the 12-hour time to 24-hour format

    std::string time24Hour = convertTo24HourClock(time12Hour);
        // Output the time in 24-hour format

    std::cout << time24Hour << std::endl;

    return 0;
}
