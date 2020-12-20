class Flight:
    def __init__(self,capacity,):
        self.capacity = capacity
        self.passengers = []
        self.cargo = []
        self.count_of_pass = 0
        
        
    def Add_passenger(self,client):
        if self.count_of_pass == self.capacity:
            print("Can't add passenger.Capacity is full")
        else:
            self.passengers.append(client)
            self.count_of_pass += 1
            self.passengers[self.count_of_pass-1].seat = self.count_of_pass-1

    def Cancel_reservation(self,client):
        self.passengers.remove(client)

    def Add_luggage(self,lugage):
        self.cargo.append(lugage)

class Client:
    def __init__(self,name,passport):
        self.name = name
        self.passport = passport
        self.seat = -1


class Luggage:
    def __init__(self,weigth,id,owner):
        self.weigth = weigth
        self.id = id
        self.owner = owner

#MAIN
flight = Flight(10)

client = Client("Vladi",123)
client2 = Client("Gosho",13)

flight.Add_passenger(client)
flight.Add_passenger(client2)

#luggage = Luggage(12,21,)

print(len(flight.passengers))
for c in flight.passengers:
    print("Client name:{0} passport:{1}".format(c.name,c.passport))
