from datetime import date


def exchange(bgn_amount, currency, exchange_date):
    valute_course = 0
    if currency == "EUR":
        valute_course = 0.511292
    elif currency == "TRY":
        valute_course = 1.46 + 0.0014*(exchange_date - date(2014, 8, 28)).days

    exchanged_money = bgn_amount * valute_course
    return exchanged_money


print(exchange(1, 'EUR', date(2020, 10, 14)))  
print(exchange(42, 'EUR', date.today()))
print(exchange(1, 'TRY', date(2014, 8, 28)))
print(exchange(1, 'TRY', date(2020, 10, 14)))
