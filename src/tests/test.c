#include "test.h"

void run_suite(Suite *suite) {
    SRunner *suite_runner = srunner_create(suite);
  srunner_run_all(suite_runner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  if (failed_count != 0) {
    exit(1);
  }

}

int main() {
  const int suites_cnt = 1;
  Suite *suites[] = {
    init_suite_common(),
    // init_suite_comparsion()
  };
  
  for (int i = 0; i < suites_cnt; i++) {
    run_suite(suites[i]);
  }

}