(defun nth-element (lst n)
  (if (or (null lst) (< n 1))
      nil
      (if (= n 1)
          (first lst)
          (nth-element (rest lst) (- n 1)))))
