# IMDB sorter cli

## Описание

Утилита командной строки, сортирующая десять самых рейтенговых
сериалов, суммарная длительность эпизодов которых не превышает числа
минут переданного в аргументах.

## Системные требования  

* Компилятор с поддержкой C++20
* Библиотека pthread

## Использование

Программа работает с датасетом официального сайта IMDB https://datasets.imdbws.com.
Для запуска утилиты требуется передать в качестве аргументов командной строки пути
к файлам basics.tsv, ratings.tsv, episodes.tsv, akas.tsv 
и целое положительное число, отражающее максимальную длительность всех эпизодов в минутах.

Пример:

    imdb base=basics.tsv rating=ratings.tsv episode=episodes.tsv akas=akas.tsv runTime=1263

В датасете может отсутствовать параметр runtime для некоторых или всех эпизодов сериала,
в этом случае они не обрабатываются.

Возможный вывод:

    Base load has been started
    Akas load has been started
    Rate load has been started
    Episode load has been started
    
    Load has been finished
    
    TOP TEN
    
    Id          Titletype   Title                                                       IsAdult     NumVotes    Rating      RunTime     
    tt26493973  tvSeries    Jinny's Kitchen                                             0           2668        9.5         195         
    tt7866314   tvSeries    BTS: Bon Voyage                                             0           2160        9.5         0           
    tt2298792   tvSeries    Alpha Bravo Charlie                                         0           1801        9.5         0           
    tt3062514   tvSeries    Khawatir                                                    0           3208        9.5         0           
    tt8203520   tvSeries    I stin Alpha i sti Vita oloi pan gia ti marmita             0           1128        9.6         0           
    tt7865962   tvSeries    Run BTS!                                                    0           2380        9.6         0           
    tt10680606  tvSeries    Minecraft Epic                                              0           3970        9.6         748         
    tt8560994   tvSeries    Friday Five Sharp                                           0           4080        9.8         0           
    tt7151672   tvSeries    Choufli Hal                                                 0           2590        9.8         55          
    tt10116578  tvSeries    Call Me Kevin                                               0           1796        9.8         0
    
    Process finished with exit code 0
