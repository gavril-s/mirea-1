import os
import random

def partition(array, low, high):
    pivot = array[high]

    i = low - 1
 
    for j in range(low, high):
        if array[j] <= pivot:
            i += 1
            (array[i], array[j]) = (array[j], array[i])

    (array[i + 1], array[high]) = (array[high], array[i + 1])

    return i + 1
 
def quicksort_adv(array, low, high):
    if low < high:
        pi = partition(array, low, high)
        quicksort_adv(array, low, pi - 1)
        quicksort_adv(array, pi + 1, high)

def quicksort(array):
    quicksort_adv(array, 0, len(array) - 1)

def main():
    os.system("chcp 65001 > nul")

    ESC = "\033["
    WHITE_BACKGROUD = "47"
    WHITE_TEXT = "37"
    BLACK_BACKGROUND = "40"
    BLACK_TEXT = "30"
    RESET = "\033[m"

    whites = []
    blacks = []

    for i in range(8):
        for j in range(8):
            num = random.randint(1, 100)
            num_string = " " * (3 - len(str(num))) + str(num)

            if (i + j) % 2 == 0:
                background_color = WHITE_BACKGROUD
                text_color = BLACK_TEXT
                whites.append(num)
            else:
                background_color = BLACK_BACKGROUND
                text_color = WHITE_TEXT
                blacks.append(num)
                
            print(ESC + background_color + ";" + text_color + "m" + num_string + RESET, end=" ")
        print()          
    
    choice = ""
    while choice != "0" and choice != "1":
        print("Выберите цвет фигур (0 - белые, 1 - чёрные):", end=" ")
        try:
            choice = input()
            if choice != "0" and choice != "1":
                print("Неверный ввод!")
        except KeyboardInterrupt:
            print()
            print("Неверный ввод!")
        except EOFError:
            print("Неверный ввод!")

    if choice == "0":
        quicksort(whites)
        print(whites)
    elif choice == "1":
        quicksort(blacks)
        print(blacks)
    else:
        print('Неверный ввод!', end=" ")

if __name__ == "__main__":
    main()