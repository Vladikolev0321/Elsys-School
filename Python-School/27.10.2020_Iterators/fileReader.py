class FileReader:
    def __init__(self, file_name):
        self.file_name = file_name
        self.__file = open(self.file_name, 'r')

    def __iter__(self):
        #self.__file = open(self.file_name,'r')
        return iter(self.__file)
        #return self
    def __next__(self):
        line = self.__file.readline()
        if not line:
            self.__file.close()
            raise StopIteration
        return line

filereader = FileReader('toReadFrom.txt')
for i in filereader:
    print(i)
