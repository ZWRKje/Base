#include <iostream>
#include <string> 


struct Language {
    std::string value;
    explicit Language (std::string initValue) {
        value = initValue;
    }
};

struct Task {
    std::string value;
    explicit Task(std::string initValue) {
        value = initValue;
    }
};

struct Week {
    std::string value;
    explicit Week(std::string initValue) {
        value = initValue;
    }
};


struct Study {
    std::string specialization;
    std::string course;
    std::string week;
    Study(Language initLanguage, Task initTask, Week initWeek) {
        specialization = initLanguage.value;
        course = initTask.value;
        week = initWeek.value;
    }

};


int main() {
   Study title(
      Language("C++"),
      Task("explicit"),
      Week("4th")
   );

   return 0;
}