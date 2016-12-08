from Vector import Vector

class SquareMatrix:
  
  def __init__(self, size):
    self.size = size;
    self.matrix = [[0 for j in range(size)] for i in range(size)];
    
  
  def getSize(self):
    return self.size
  
  def get(self, i, j):
    return self.matrix[i][j]
  
  def set(self, i, j, val):
    self.matrix[i][j] = val
  
  def multNumber(self, val):
    result = SquareMatrix(self.size)
    for i in range(0, self.size, 1):
      for j in range(0, self.size, 1):
        result.matrix[i][j] = self.matrix[i][j] * val
    return result

  def multVector(self, vector):
    result = Vector(self.size)
    for i in range(0, self.size, 1):
      result.set(i, 0)
      for j in range(0, self.size, 1):
        result.set(i, result.get(i) + vector.get(i) * self.matrix[i][j])
    return result

  def multMatrix(self, matrix):
    result = SquareMatrix(self.size)
    for i in range(0, self.size, 1):
      for j in range(0, self.size, 1):
        result.matrix[i][j] = 0
        for k in range(0, self.size, 1):
          result.matrix[i][j] += self.matrix[i][k] * matrix.matrix[k][j]
    return result

  def trans(self):
    result = SquareMatrix(self.size)
    for i in range(0, self.size, 1):
      for j in range(0, self.size, 1):
        result.matrix[j][i] = self.matrix[i][j]
    return result
    
  def min(self):
    return min([min(self.matrix[i]) for i in range(self.size)])

  def max(self):
    return max([max(self.matrix[i]) for i in range(self.size)])

  def sort(self):
    result = SquareMatrix(self.size)
    for i in range(self.size):
      result.matrix[i] = self.matrix[i][:]
      result.matrix[i].sort()
    return result

  def plusMatrix(self, matrix):
    result = SquareMatrix(self.size)
    for i in range(self.size):
      for j in range(self.size):
        result.matrix[i][j] = self.matrix[i][j] + matrix.matrix[i][j]
    return result