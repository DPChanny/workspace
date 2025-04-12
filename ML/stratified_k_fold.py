from sklearn.tree import DecisionTreeClassifier
from sklearn.model_selection import StratifiedKFold
from sklearn.datasets import load_iris
from sklearn.metrics import accuracy_score
from numpy import mean
from pandas import DataFrame

iris = load_iris()
iris_df = DataFrame(data=iris.data, columns=iris.feature_names)
iris_df['label'] = iris.target

skf = StratifiedKFold(n_splits=5)

dtc = DecisionTreeClassifier()

accuracies = []

for i_train, i_test in skf.split(iris_df, iris_df['label']):
    r_train, c_train = iris_df.iloc[i_train, iris_df.columns != 'label'], iris_df['label'].iloc[i_train]
    r_test, c_test = iris_df.iloc[i_test, iris_df.columns != 'label'], iris_df['label'].iloc[i_test]

    dtc.fit(r_train, c_train)

    accuracies.append(accuracy_score(c_test, dtc.predict(r_test)))

print(mean(accuracies))
