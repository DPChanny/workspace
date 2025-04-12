from sklearn.datasets import load_iris
from sklearn.preprocessing import MinMaxScaler
from sklearn.preprocessing import StandardScaler
from pandas import DataFrame

iris = load_iris()
iris_df = DataFrame(iris.data, columns=iris.feature_names)
print(iris_df.mean())
print(iris_df.var())

iris_scaled = StandardScaler().fit_transform(iris_df)
iris_scaled_df = DataFrame(iris_scaled, columns=iris.feature_names)
print(iris_scaled_df.mean())
print(iris_scaled_df.var())

iris_scaled = MinMaxScaler().fit_transform(iris_df)
iris_scaled_df = DataFrame(iris_scaled, columns=iris.feature_names)
print(iris_scaled_df.max())
print(iris_scaled_df.min())
