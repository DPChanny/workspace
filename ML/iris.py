from sklearn.datasets import load_iris
from sklearn.tree import DecisionTreeClassifier
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score
import pandas as pd

RANDOM_STATE = 11

# 붓꽃 데이터 세트 로드
iris = load_iris()

# 붓꽃 열 데이터
iris_data = iris.data

# 붗꽃 데이터 열 이름
# print(iris.feature_names)

# 붓꽃 열 데이터 종류
iris_label = iris.target
# print(iris_label)
# 붓꽃 열 데이터 종류 이름
# print(iris.target_names)

# 붓꼿 데이터 프레임 생성
iris_df = pd.DataFrame(data=iris_data, columns=iris.feature_names)
# 붓꼿 열 데이터 종류 추가
iris_df['label'] = iris_label

# 테스트 데이터 x_test, y_test
# 학습 데이터 x_train, y_train
x_train, x_test, y_train, y_test = train_test_split(iris_data, iris_label, test_size=0.2, random_state=RANDOM_STATE)

# 의사 결정 트리 객체 생성
dt_clf = DecisionTreeClassifier(random_state=RANDOM_STATE)

# 의사 결정 트리 학습
dt_clf.fit(x_train, y_train)

# 의사 결정 트리 예측
predict = dt_clf.predict(x_test)

# 의사 결정 트리 예측 정확도
print(accuracy_score(predict, y_test))
