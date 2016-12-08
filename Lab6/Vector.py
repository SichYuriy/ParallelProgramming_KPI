class Vector:
  
  def __init__(self, size):
    self.size = size
    self.vector = [0 for i in range(size)]
  
  def getSize(self):
    return self.size

  def get(self, i):
    return self.vector[i]
  
  def set(self, i, val):
    self.vector[i] = val

  def multNumber(self, val):
    return [(self.vector[i] * val) for i in range(self.size)]
  
  def multMatrix(self, matrix):
    result = Vector(self.size)
    for i in range(self.size):
      result.vector[i] = 0
      for j in range(self.size):
        result.vector[i] += self.vector[i] * matrix.get(j, i)
    return result

  def multVector(self, vector):
    result = 0
    for i in range(self.size):
      result += self.vector[i] * vector.get(i)
    return result
  
  def sort(self):
    result = Vector(self.size)
    result.vector = self.vector[:]
    result.vector.sort()
    return result

  def min(self):
    return min(self.vector)
  
  def max(self):
    return max(self.vector)
  
  def plusVector(self, vector):
    result = Vector(self.size)
    result.vector = [(self.vector[i] + vector.get(i)) for i in range(self.size)]
    return result