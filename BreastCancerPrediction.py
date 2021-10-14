from sklearn.linear_model import LogisticRegression
from sklearn.tree import DecisionTreeClassifier, export_graphviz
import graphviz
from sklearn.model_selection import train_test_split, GridSearchCV
from IPython.display import Image
from sklearn.metrics import accuracy_score, precision_score, recall_score, f1_score, precision_recall_fscore_support
import pandas as pd

########## Logistic Regression Model ##########
df = pd.read_csv(r'C:\BreastCancer.csv')
X = df[['Mean radius','Mean texture','Mean perimeter','Mean area','Mean smoothness','Mean compactness','Mean concavity','Mean concave points','Mean symmetry','Mean fractal dimension','Radius error','Texture error','Perimeter error','Area error','Smoothness error','Compactness error','Concavity error','Concave points error','Symmetry error','Fractal dimension error','Worst radius','Worst texture','Worst perimeter','Worst area','Worst smoothness','Worst compactness','Worst concavity','Worst concave points','Worst Symmetry','Worst fractal dimension']].values
df['target'] = df['Outcome'] == 'malignant'
y = df['target'].values
model = LogisticRegression(solver = 'liblinear')
X_train, X_test, y_train, y_test = train_test_split(X, y, random_state=5)
#print("whole dataset:",X,y)
#print("Dataset used for training:",X_train,y_train)
#print("dataset used for testing:",X_test,y_test)
model.fit(X_train,y_train)
y_pred = model.predict(X_test)
print("Score by Logistic Regression Model : {}%".format(model.score(X_test,y_test)*100))
print("Accuracy by Logistic Regression Model : {}%".format(accuracy_score(y_test,y_pred)*100))
print("Precision by Logistic Regression Model : {}%".format(precision_score(y_test,y_pred)*100))
print("Recall by Logistic Regression Model : {}%".format(recall_score(y_test,y_pred)*100))
print("F1 score by Logistic Regression Model : {}%\n".format(f1_score(y_test,y_pred)*100))

########## Decision Tree Model ##########
df = pd.read_csv(r'C:\BreastCancer.csv')
feature_names = ['Mean radius','Mean texture','Mean perimeter','Mean area','Mean smoothness','Mean compactness','Mean concavity','Mean concave points','Mean symmetry','Mean fractal dimension','Radius error','Texture error','Perimeter error','Area error','Smoothness error','Compactness error','Concavity error','Concave points error','Symmetry error','Fractal dimension error','Worst radius','Worst texture','Worst perimeter','Worst area','Worst smoothness','Worst compactness','Worst concavity','Worst concave points','Worst Symmetry','Worst fractal dimension']
X = df[feature_names].values
df['target'] = df['Outcome'] == 'malignant'
y = df['target'].values
param_grid = {
    'max_depth' : [5,10,15,20,25,30,35,40,45,50],
    'min_samples_leaf' : [1,2,3,4,5,6,7,8,9,10],
    'max_leaf_nodes' : [5,10,15,20,25,30,35,40,45,50]
}
dt = DecisionTreeClassifier()
gs = GridSearchCV(dt, param_grid, scoring= 'f1', cv = 5)
gs.fit(X,y)
X_train, X_test, y_train, y_test = train_test_split(X, y, random_state = 54)
dt = DecisionTreeClassifier(max_depth = gs.best_params_['max_depth'], min_samples_split = gs.best_params_['min_samples_leaf'], max_leaf_nodes = gs.best_params_['max_leaf_nodes'])
dt.fit(X_train, y_train)
y_pred = dt.predict(X_test)
print("Score by Decision Tree Model : ",dt.score(X_test, y_test)*100)
print("Accuracy by Decision Tree Model : ",accuracy_score(y_test, y_pred)*100)
print("Precision by Decision Tree Model : ",precision_score(y_test, y_pred)*100)
print("Recall by Decision Tree Model : ",recall_score(y_test, y_pred)*100)
#dot_file = export_graphviz(dt, feature_names = feature_names)
#graph = graphviz.Source(dot_file)
#graph.render(filename='BreastCancerPredictionTree', format='png', cleanup=True)'''