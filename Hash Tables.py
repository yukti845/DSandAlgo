
class Hashtable:
    def __init__(self):
        self.bucket = 16
        self.hashmap = [[] for i in range(self.bucket)]

    def hash(self, key):
        return len(key) % self.bucket

    def put(self, key, value):
        hash_value = self.hash(key)
        reference = self.hashmap[hash_value]
        for i in range(len(reference)):
            if reference[i][0] == key:
                reference[i][1] = value
                return None
        reference.append([key, value])
        return None

    def get(self, key):
        hash_value = self.hash(key)
        reference = self.hashmap[hash_value]
        for i in range(len(reference)):
            if reference[i][0] == key:
                return reference[i][1]
        return -1

    def remove(self, key):
        hash_value = self.hash(key)
        reference  = self.hashmap[hash_value]
        for i in range(len(reference)):
            if reference[i][0] == key:
                reference.pop(i)
                return None
        return None

h = Hashtable()
h.put('grapes', 1000)
h.put('apples', 10)
h.put('orange', 300)
h.put('banana', 200)
print(h.get('grapes'))
print(h)
h.remove('apples')
print(h)


# First recurring character

def func(mylist):
    for i in range(len(mylist)):
        for j in range(i+1, len(mylist)):
            if mylist[i] == mylist[j]:
                return mylsit[i]
    return 0

def hashtables(mylist):
    mydict = {}
    for i in range(len(mylist)):
        if mylist[i] in mydict:
            return mylist[i]
        else:
            mydict[mylist[i]] = i
    return 0

mylist = [2,1,1,2,3,4,5]
x = hashtables(mylist)
print(x)