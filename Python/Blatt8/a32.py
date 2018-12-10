#!/usr/bin/env python3


def auskunft(linie, start, ziel):
    """Function to find given route"""
    if start == ziel:  # if start is goal return 0
        return 0, start
    haltestellen_dict = {}
    haltestellen = [start]
    time = 0
    for line in open("./a32-fahrzeiten.txt").readlines():  # read in file, seperate lines and build dict with stops data
        line_data = line.split(";")
        if line_data[0] in haltestellen_dict:  # if line exists in dict append data to list, else create new dict entry
            haltestellen_dict[line_data[0]].append(
                {"start": line_data[1].strip(), "end": line_data[2].strip(), "time": int(line_data[3].strip())})
        else:
            haltestellen_dict[line_data[0]] = [
                {"start": line_data[1].strip(), "end": line_data[2].strip(), "time": int(line_data[3].strip())}]
    while start != ziel:  # while start is not goal append data to tuple and move start to next station
        for item in haltestellen_dict[linie]:
            if start == item["start"]:
                time += item["time"]
                haltestellen.append(item["end"])
                start = item["end"]
                break
    return time, haltestellen


print(auskunft("Bus6", "Nordfriedhof", "Nordfriedhof"))  # test 1
minutes, path = auskunft("S9", "Kelsterbach", "Niederrad")  # task
print(minutes, "Minuten so: ", path)
minutes, path = auskunft("S9", "Wiesbaden Ost", "Ruesselsheim")  # personal test
print(minutes, "Minuten so:", path)
