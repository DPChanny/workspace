from sklearn.datasets import load_iris
from sklearn.tree import DecisionTreeClassifier
from sklearn.metrics import accuracy_score
from sklearn.model_selection import KFold
import numpy as np

RANDOM_STATE = 11

# 붓꽃 데이터 세트 로드
iris = load_iris()

# 의사 결정 트리 객체 생성
dtc = DecisionTreeClassifier(random_state=RANDOM_STATE)

# K Fold 교차 검증 객체 생성
k_fold = KFold(n_splits=5)

# k번 교차 검증 정확도
accuracies = []

for i_train, i_test in k_fold.split(iris.data):
    x_train, x_test = iris.data[i_train], iris.data[i_test]
    y_train, y_test = iris.target[i_train], iris.target[i_test]

    dtc.fit(x_train, y_train)
    predict = dtc.predict(x_test)

    accuracies.append(accuracy_score(y_test, predict))

print(np.mean(accuracies))
