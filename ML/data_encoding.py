from sklearn.preprocessing import LabelEncoder
from sklearn.preprocessing import OneHotEncoder

label = ['사자', '기린', '기린', '코끼리']

enc = LabelEncoder()
enc.fit(label)
print(enc.classes_)
transform = enc.transform(label)
print(transform)
print(enc.inverse_transform(transform))

enc = OneHotEncoder()
transform = transform.reshape(-1, 1)
print(transform)
enc.fit(transform)
print(enc.transform(transform).toarray())
