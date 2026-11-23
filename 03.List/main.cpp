#include <iostream>
#include <string>
#include <list>
#include <windows.h>

using namespace std;

/*
==========================================================================================================================================
                                                      Контейнер list
==========================================================================================================================================

                                                          LIST
  list<T> — двозв'язний список: кожен елемент окремо в динамічній пам'яті і знає попередній та наступний.
  Вставка і видалення в БУДЬ-ЯКОМУ місці швидкі: інші елементи не зсуваються, а ітератори на них залишаються дійсними.
  Доступу за номером немає: щоб дійти до n-го елемента, треба пройти n кроків.
  Використовують, коли елементи часто вставляють і видаляють у середині: плейлист, черга з пропусками, порядок шарів у редакторі.
  В інших випадках vector зазвичай швидший.

  ----------------------------------------------------------------------------------------------------------------------------------------

  Основні методи:
      push_back(x)   push_front(x)      додати в кінець / на початок
      pop_back()     pop_front()        прибрати з кінця / з початку
      front()        back()             перший / останній
      insert(it, x)                     вставити ПЕРЕД ітератором
      erase(it)                         видалити елемент за ітератором
      remove(x)                         видалити всі елементи, рівні x
      size()  empty()  clear()
  Ітератор двоспрямований: ++it і --it працюють, it + n — ні.
*/

// Плейлист: пісні можна вставляти в будь-яке місце
class Playlist
{
private:
    list<string> songs;

public:
    void add(const string& song)
    {
        songs.push_back(song);
    }

    void playNext(const string& song)
    {
        songs.push_front(song);                  // «Відтворити наступною»
    }

    // Вставити song перед піснею before
    void insertBefore(const string& before, const string& song)
    {
        for (auto it = songs.begin(); it != songs.end(); ++it)
        {
            if (*it == before)
            {
                songs.insert(it, song);          // інші пісні не зсуваються в пам'яті
                return;
            }
        }
        cout << "Пісню " << before << " не знайдено" << endl;
    }

    void removeSong(const string& song)
    {
        songs.remove(song);
    }

    void print() const
    {
        int number = 1;
        for (const string& song : songs)
        {
            cout << "  " << number++ << ". " << song << endl;
        }
    }
};

int main()
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    Playlist playlist;
    playlist.add("Shape of You");
    playlist.add("Believer");
    playlist.add("Numb");
    playlist.print();

    cout << "--- Відтворити наступною ---" << endl;
    playlist.playNext("Bohemian Rhapsody");
    playlist.print();

    cout << "--- Вставка і видалення ---" << endl;
    playlist.insertBefore("Numb", "Thunder");
    playlist.removeSong("Believer");
    playlist.print();

    return 0;
}

/*
==========================================================================================================================================
                                                              ПРАКТИКА
==========================================================================================================================================

  Завдання. Поїзд.
    - Клас Train:
        поле list<string> wagons;
        метод void attachToEnd(const string& wagon)   — причепити вагон у кінець (push_back);
        метод void attachToFront(const string& wagon) — причепити одразу за локомотивом, на початок (push_front);
        метод void insertAfter(const string& after, const string& wagon) — вставити вагон ПІСЛЯ вагона after:
          знайдіть after циклом з ітератором, зробіть ++it і insert (як insertBefore у прикладі);
          якщо after немає — «Вагон Ресторан не знайдено»;
        метод void detach(const string& wagon) — відчепити вагон (remove);
        метод void print() const — виводить «Локомотив - Купе - Плацкарт - Ресторан».
  У main:
    - причепіть у кінець «Купе», «Плацкарт»; на початок — «СВ»; виведіть поїзд;
    - вставте «Ресторан» після «Купе», виведіть поїзд;
    - відчепіть «Плацкарт», спробуйте вставити вагон після «Пошта»; виведіть поїзд.
*/
