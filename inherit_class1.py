class Employ:
	count=0
	def __init__(self,fname,lname,age,pay):
		Employ.count+=1
		self.fname=fname
		self.lname=lname
		self.age=age
		self.pay=pay
		self.email=fname+"."+lname+"@gmail.com"

	def details(self):
		print(f"Name : {self.fname} {self.lname}")
		print(f"Email : {self.email}")
		print(f"Age : {self.age}")
		print(f"Pay : {self.pay}")



class developer(Employ):
	def __init__(self,fname,lname,age,pay,lang):
		super().__init__(fname,lname,age,pay)
		self.lang=lang
	
	def details(self):
		super().details()
		print(f"Language : {self.lang}")


class manager(Employ):
	def __init__(self,fname,lname,age,pay,employ=None):
		super().__init__(fname,lname,age,pay)
		if(employ==None):
			self.employ=[]
		else:
			self.employ=employ

	def details(self):
		super().details()
		for emp in self.employ:
			emp.details()

	def add_employ(self,emp):
		if emp not in self.employ:
			self.employ.append(emp)

	def remove_employ(self,emp):
		if emp in self.employ:
			self.employ.remove(emp)






d1=developer("Pankaj","Kumar",24,7283284,"Cplusplus")
d2=developer("Avinash","Prasad",23,7857385,"Java")



# d1.details()

m1=manager("Vishal","Shivam",23,723782433,[d1,d2])

m1.details()

m1.remove_employ(d1)

print(isinstance(d1,developer))
print(issubclass(manager,Employ))


help(manager)

print()

m1.details()







