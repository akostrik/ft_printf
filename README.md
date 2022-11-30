# ft_printf
A project of 42 School

Solo, about 70 hours

How to run:

```$ make```
--------------------------------------------------------
Tester https://github.com/paulo-santana/ft_printf_tester

basic test: 
  1.OK 
%c basic: 
  2.OK 3.OK 4.OK 5.OK 6.OK 7.OK 8.OK 9.OK 10.OK 11.OK 
%s basic: 
  12.OK 13.OK 14.OK 15.OK 16.OK 17.OK 18.OK 19.OK 20.OK 21.OK 22.OK 23.OK 24.OK 25.OK 26.OK 27.OK 
  28.KO (Wrong output) (Wrong return)
        Expected: [(null)], return: 6
        Got:      [], return: 0
     You can rerun this test with sh test 28
     The function was called like this:
   ft_printf("%s", null_str);

  29.KO (Wrong output) (Wrong return)
        Expected: [(null) everywhere], return: 17
        Got:      [ everywhere], return: 11
     You can rerun this test with sh test 29
     The function was called like this:
   ft_printf("%s everywhere", null_str);

  30.KO (Wrong output) (Wrong return)
        Expected: [everywhere (null)], return: 17
        Got:      [everywhere ], return: 11
     You can rerun this test with sh test 30
     The function was called like this:
   ft_printf("everywhere %s", null_str);
31.OK 32.OK 33.OK 
%p basic: 
  34.OK 35.OK 36.OK 37.OK 38.OK 39.OK 40.OK 41.OK 42.OK 43.OK 
%d basic: 
  44.OK 45.OK 46.OK 47.OK 48.OK 49.OK 50.OK 51.OK 52.OK 53.OK 
%i basic: 
  54.OK 55.OK 56.OK 57.OK 58.OK 59.OK 
%u basic: 
  60.OK 61.OK 62.OK 63.OK 64.OK 65.OK 66.OK 67.OK 
%x basic: 
  68.OK 69.OK 70.OK 71.OK 72.OK 73.OK 74.OK 75.OK 76.OK 77.OK 78.OK 
%X basic: 
  79.OK 80.OK 81.OK 82.OK 83.OK 84.OK 85.OK 86.OK 87.OK 88.OK 89.OK 
%% basic: 
  90.OK 91.OK 92.OK 93.OK 94.OK 95.OK 
mix: 
  96.OK 97.OK 98.OK 99.OK 
  100.KO (Wrong output) (Wrong return)
        Expected: [b - (null) - (nil) 20 - -20 - 4294967295 - ffffffff BEBC200 %], return: 61
        Got:      [b -  - (nil) 20 - -20 - 4294967295 - ffffffff BEBC200 %], return: 55
     You can rerun this test with sh test 100
     The function was called like this:
   ft_printf("%c - %s - %p %d - %i - %u - %x %X %%", 'b', null_str, ((void*)0), 20, -20, -1, -1, 200000000);

  101.KO (Wrong output) (Wrong return)
        Expected: [\0 (null) - 0xdeadc0de - 0 - -2147483648 4294967295 - ffffffff - BEBC200 %], return: 73
        Got:      [\0  - 0xdeadc0de - 0 - -2147483648 4294967295 - ffffffff - BEBC200 %], return: 67
     You can rerun this test with sh test 101
     The function was called like this:
   ft_printf("%c %s - %p - %d - %i %u - %x - %X %%", '\0', null_str, (void *)0xdeadc0de, 0, (int)-2147483648, -1, -1, 200000000);

----------------------------------------------------------
Tester https://github.com/Tripouille/printfTester 

---------------------------------------------------------
Tester https://github.com/gavinfielder/pft
