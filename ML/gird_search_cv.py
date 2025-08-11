from sklearn.datasets import load_iris
from sklearn.model_selection import GridSearchCV
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier
from pandas import DataFrame
from sklearn.metrics import accuracy_score

grid_params = dict(max_depth=[1, 2, 3], min_samples_split=[2, 3])

iris = load_iris()

train_x, test_x, train_y, test_y = train_test_split(
    iris.data, iris.target, test_size=0.2, random_state=121
)

grid = GridSearchCV(
    DecisionTreeClassifier(random_state=11),
    param_grid=grid_params,
    cv=3,
    refit=True,
)

grid.fit(train_x, train_y)

grid_df = DataFrame(grid.cv_results_)
print(
    grid_df[
        [
            "params",
            "mean_test_score",
            "rank_test_score",
            "split0_test_score",
            "split1_test_score",
            "split2_test_score",
        ]
    ]
)

predict = grid.best_estimator_.predict(test_x)
print(accuracy_score(predict, test_y))
