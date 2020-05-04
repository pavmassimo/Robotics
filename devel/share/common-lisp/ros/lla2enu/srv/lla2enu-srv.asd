
(cl:in-package :asdf)

(defsystem "lla2enu-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "distance" :depends-on ("_package_distance"))
    (:file "_package_distance" :depends-on ("_package"))
  ))