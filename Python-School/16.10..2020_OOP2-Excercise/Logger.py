class Logger:
    def log(self, message):
        raise NotImplementedError("Not implemented")
        #print(message)
    def info()

class StdOutLogger(Logger):
    def log(self,message):
        print(message)

class FileLogger(Logger):
    def __init__(self, file_name):
        self.__file = open(file_name, 'a')

    def log(self, message):
        self.__file.write(message)

    def __del__(self):
        self.__file.close()


logger = StdOutLogger()
logger.log("Hello")

fileLog = FileLogger("t1.txt")
fileLog.log("opa")
