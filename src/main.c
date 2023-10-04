#include "for_test/check_main.h"

int main(void) {
  int no_failed = 0;
  Suite *test_all[] = {
      s21_sub_suite(),                    // done
      s21_add_suite(),                    // done
      s21_is_not_equal_suite(),           // done
      s21_is_equal_suite(),               // done
      s21_is_greater_suite(),             // done
      s21_is_greater_or_equal_suite(),    // done
      s21_is_less_suite(),                // done
      s21_is_less_or_equal_suite(),       // done
      s21_mul_suite(),                    // done
      s21_div_suite(),                    // done
      s21_mod_suite(),                    // done
      s21_negate_suite(),                 // done
      s21_truncate_suite(),               // done
      s21_floor_suite(),                  // done
      s21_is_dec_to_int(),                // done
      s21_is_int_to_dec_21(),             // done
      s21_is_from_decimal_to_float(),     // done
      s21_from_float_to_decimal_suite(),  // done
      s21_round_suite()                   // done
  };

  SRunner *runner;
  runner = srunner_create(test_all[0]);
  srunner_set_fork_status(runner, CK_NOFORK);
  for (size_t i = 1; i < (sizeof((test_all)) / sizeof((test_all)[0])); i++)
    srunner_add_suite(runner, test_all[i]);

  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
