(defun nth-element (lst n)
    (nth (- n 1) lst))

(write (nth-element `(1 2 3 4) 2))
