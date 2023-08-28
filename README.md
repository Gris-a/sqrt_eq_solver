# Quadratic equation solver

Программа, решающая квадратное уравнение.

## Installation

- Clone this repository

```
git clone https://github.com/Gris-a/sqrt_eq_solver
```

- Compile program

```
cd sqrt_eq_solver/src
g++ flag_check.cpp main.cpp solve.cpp tests.cpp user.cpp -o solver.out
```

## Usage

- Run program

```
./<program name> [options]
```

### Run options:

- --help&emsp;&emsp;&emsp;Prints info about program usage.

- --test&emsp;&emsp;&emsp;Run tests from tests.txt.

- --user&emsp;&emsp;&emsp;Solve equation with user input-output.

## About The Program

Основные структуры(roots, coefficients и test_input, arguments) и константы(M_ERR, my_args, nRoots) определены в файле main.h.

### Solving equation

Функции для вычислений определены в файле solve.cpp. При вычислениях погрешность всех чисел считается равной M_ERR, определённой в main.h.\
Если уравнение не имеет корней, то их значение равно значению при инициализации, то есть 0.\
Если уравнение имеет один корень, то его значение присваивается обеим переменным в структуре.

#### Note: Если у уравнения два корня, отличающихся менее, чем на M_ERR, то считается, что уравнение имеет один корень.

### Testing program(--test)

Тестирующие функции определены в файле tests.cpp. Программа тестирует значения, указанные в файле tests.txt. Значения в файле упорядочены согласно структуре test_input.\
По завершении тестирования выводятся провальные тесты и количество успешно прошедших.

### User interface(--user)

Функции для взаимодействия с пользователем определены в файле user.cpp. Программа просит на ввод коэффициенты, задуманные пользователем и на их основе решает квадратное уравнение.\
При некорректном вводе программа повторно запрашивает коэффициент.

## Author
Идея: [ДЕД](https://vk.com/ded32_ru)\
Разработал: [Gris-a](https://github.com/Gris-a/)\
Telegram: [GraY](https://t.me/qgrayq)

## Project status

Closed
