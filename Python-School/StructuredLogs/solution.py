def filter_logs(logs, key, value):
    res = []
    for log in logs:
        if log[key] == value:
            res.append(log)
    return res


def top(logs, key, count):
    list_of_values = []
    di = {}
    for log in logs:
        if log[key] in list_of_values:
            pass
        else:
            list_of_values.append(log[key])

    for value in list_of_values:
        for log in logs:
            if log[key] == value:
                if(value in di.keys()):
                    di[value] += 1
                else:
                    di[value] = 1

    sorted_dict = sorted(di.items(), key=lambda x: x[1], reverse=True)
    while(len(sorted_dict) > count):
        sorted_dict.pop()

    return dict(sorted_dict)


def complex_filter(logs, filter_params):
    result = []
    for log in logs:
        does_it_pass = True
        for key, value in filter_params.items():
            if log[key] != value:
                does_it_pass = False
        if(does_it_pass):
            result.append(log)

    return result





#logs = [
#   {"timestamp": "2020-05-11T13:42:50", "status": "error", "countryISO2": "BG"},
#   {"timestamp": "2020-05-11T13:43:20", "status": "success", "countryISO2": "UK"},
#   {"timestamp": "2020-05-11T13:44:30", "status": "success", "countryISO2": "NZ"},
#]
#print(filter_logs(logs, "status", "success"))
#print(filter_logs(logs, "countryISO2", "BG"))

#-----------------------------------
#print(top(logs, "countryISO2", 5))
#print(top(logs, "status", 3))

#print(complex_filter(logs, {"status": "success", "countryISO2": "NZ"}))
#print(complex_filter(logs, {"status": "error", "countryISO2": "UK"}))
#print(complex_filter(logs, {"status": "error"}))
#print(complex_filter(logs, {}))