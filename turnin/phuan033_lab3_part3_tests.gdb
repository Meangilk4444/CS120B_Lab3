# Test file for "Lab3_bitManipulation"


# commands.gdb provides the following functions for ease:
#   test "<message>"
#       Where <message> is the message to print. Must call this at the beginning of every test
#       Example: test "PINA: 0x00 => expect PORTC: 0x01"
#   checkResult
#       Verify if the test passed or failed. Prints "passed." or "failed." accordingly, 
#       Must call this at the end of every test.
#   expectPORTx <val>
#       With x as the port (A,B,C,D)
#       The value the port is epected to have. If not it will print the erroneous actual value
#   setPINx <val>
#       With x as the port or pin (A,B,C,D)
#       The value to set the pin to (can be decimal or hexidecimal
#       Example: setPINA 0x01
#   printPORTx f OR printPINx f 
#       With x as the port or pin (A,B,C,D)
#       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary 
#       Example: printPORTC d
#   printDDRx
#       With x as the DDR (A,B,C,D)
#       Example: printDDRB

echo ======================================================\n
echo Running all tests..."\n\n

# Example test:
test "PINA: 0x30 => PORTC: 0xC0"
# Set inputs
setPINA 0x30
# Continue for several ticks
continue 5
# Set expect values
expectPORTC 0xC0
# Check pass/fail
checkResult

# Add tests belo
test "PINA: 0x72 => PORTC: 0x60"
setPINA 0x71
continue 5
expectPORTC 0x60
checkResult

test "PINA: 0x34 => PORTC: 0xF0"
setPINA 0x34
continue 5
expectPORTC 0xF0
checkResult
                                                              
test "PINA: 0x76 => PORTC: 0x38"
setPINA 0x76
continue 5
expectPORTC 0x38
checkResult

test "PINA: 0x39 => PORTC: 0xBC"
setPINA 0x39
continue 5
expectPORTC 0xBC
checkResult

test "PINA: 0x7A  => PORTC: 0x3E"
setPINA 0x7A
continue 5
expectPORTC 0x3E
checkResult

test "PINA: 0x3F => PORTC: 0xBF"
setPINA 0x3F
continue 5
expectPORTC 0xBF
checkResult
# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
