# Compiladores 20/21 - Tests runner

## **Where to place this folder**

The "test" folder should be put inside the "fir" folder

---

## **Make scripts executable**

```sh
cd test
chmod +x runTests.sh cleanTests.sh
```

---

## **Customize script behaviour**

Right at the start of the "[runTests](./runTests.sh)" script, there's two variables:

```sh
TESTDIR="tests-fir-daily-202105171721"
NONSTOP="1"
```

### **TESTDIR**

Change TESTDIR if you've made another directory with specific tests from the "tests-fir-daily" package, or even with your own tests.

If you change the TESTDIR in the "[runTests](./runTests.sh)" script, you should also do it in the "[cleanTests](./cleanTests.sh)" script

**Note:** Remember to provide the expected outputs. ( expected/{testname}.out )

### **NONSTOP**

Change NONSTOP to **"0"** if you want the test runner to pause and ask you to continue after each ERROR.

---

## **Run tests**

```sh
cd test
./runTests.sh
```

---

## **Clean all test run files**

```sh
cd test
./cleanTests.sh
```
