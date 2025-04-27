import pandas as pd
from sklearn.preprocessing import LabelEncoder
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier
from sklearn.model_selection import GridSearchCV
from sklearn.metrics import accuracy_score

titanic_df = pd.read_csv('train.csv')
y_titanic_df = titanic_df['Survived']
x_titanic_df = titanic_df.drop(['PassengerId', 'Name', 'Ticket', 'Survived'], axis=1)

x_titanic_df['Age'].fillna(x_titanic_df['Age'].mean(), inplace=True)
x_titanic_df['Cabin'].fillna('N', inplace=True)
x_titanic_df['Embarked'].fillna('N', inplace=True)
x_titanic_df['Fare'].fillna(0, inplace=True)

x_titanic_df['Sex'] = LabelEncoder().fit_transform(x_titanic_df['Sex'])
x_titanic_df['Cabin'] = LabelEncoder().fit_transform(x_titanic_df['Cabin'].str[:1])
x_titanic_df['Embarked'] = LabelEncoder().fit_transform(x_titanic_df['Embarked'])

print(x_titanic_df.head())

x_train, x_test, y_train, y_test = train_test_split(x_titanic_df, y_titanic_df, test_size=0.2)

params = {'max_depth': [2, 3, 5, 10], 'min_samples_split': [2, 3, 5], 'min_samples_leaf': [1, 5, 8]}

dtc = DecisionTreeClassifier()
grid = GridSearchCV(dtc, param_grid=params, scoring='accuracy', cv=5)
grid.fit(x_train, y_train)

predict = grid.predict(x_test)
print(accuracy_score(y_test, predict))
