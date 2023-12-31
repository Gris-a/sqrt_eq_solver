# Quadratic equation solver

Программа, решающая квадратное уравнение.

## Installation

- Clone this repository

```
git clone https://github.com/Gris-a/sqrt_eq_solver
```

- Compile program from sqrt_eq_solver folder

```
make solver.out
```

## Usage

- Run program

```
./solver.out [options] [target]
```

### Run options:

- --help&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;
    Prints info about program usage.

- --test FILE&emsp;&emsp;&emsp;&emsp;&emsp;
    Run tests from FILE.

- --user&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;
    Solve equation with user input-output.

## About The Program

### Solving equation

Функции для вычислений определены в файле solve.cpp. При вычислениях погрешность всех чисел считается равной m_err, определённой в solve.h.\
Если уравнение не имеет корней, то их значение равно значению при инициализации, то есть 0.\
Если уравнение имеет один корень, то его значение присваивается обеим переменным в структуре.

### Testing program (--test)

Тестирующие функции определены в файле tests.cpp. Программа тестирует значения, указанные в FILE. Значения в файле упорядочены согласно структуре test_input из tests.h.\
По завершении тестирования выводятся провальные тесты и количество успешно прошедших.

### User interface (--user)

Функции для взаимодействия с пользователем определены в файле user.cpp. Программа просит на ввод коэффициенты, задуманные пользователем и на их основе решает квадратное уравнение.\
При некорректном вводе программа повторно запрашивает коэффициент.

## Author
Идея: [ДЕД](https://vk.com/ded32_ru)\
Реализация: [Gris-a](https://github.com/Gris-a/)\
Telegram: [GraY](https://t.me/qgrayq)

